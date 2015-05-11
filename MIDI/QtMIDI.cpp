#include "QtMIDI.h"

QtMIDIData::QtMIDIData()
{
	this->mididata = new QList<MIDI_Node*>();
	this->total_count = 0;
}

QtMIDIData::~QtMIDIData()
{
	delete this->mididata;
}

void QtMIDIData::addNewNode(quint8 key, quint8 velocity_100ms, quint8 timbre, quint8 channel)
{
	MIDI_Node *node = new MIDI_Node();
	node->callback = NULL;
	node->channel = channel;
	node->ctl = MIDI_CTL_START|channel;
	node->duration_100ms = velocity_100ms;
	node->effect = 0;
	node->timbre = timbre;
	node->key = key;
	node->volume = 100;
	this->mididata->append(node);
	this->total_count++;
}

void QtMIDIData::addNewNode(QtMIDIData &another)
{
	this->mididata->append(*(another.mididata));
	this->total_count += another.total_count;
}

void QtMIDIData::addNewNode(MIDI_Node *newNode)
{
	this->mididata->append(newNode);
	this->total_count++;
}

MIDI_Node *QtMIDIData::at(int pos)
{
	if( pos >= 0 && pos < this->total_count)
		return (*this->mididata)[pos];
	else
		return NULL;
}

int QtMIDI::__playNextNode()
{
	bool tail = this->current < this->playdata->total_count;
	int timerInt = 0;
	while(timerInt == 0 && tail){
		MIDI_Node *node = this->playdata->at(this->current++);
		if(node != NULL){
			if(node->timbre != this->current_timbre)
				this->device->send(node->channel|MIDI_CTL_CHG_TIMBRE|((quint32)node->timbre<<8));
			this->device->send(node->word);
			timerInt = node->duration_100ms==0xff ? -2 : node->duration_100ms;
			tail = this->current < this->playdata->total_count;
			if(node->callback != NULL)
				node->callback();
		}
	}
	if(timerInt==-2) return -2;
	if(tail || timerInt<-2) return -1;
	return timerInt;
}

void QtMIDI::setTimerInterval(int t_100ms)
{
	this->timerCounter = t_100ms;
}

void QtMIDI::changeTimer(bool start)
{
	this->timerCounter = start? 0 : -1 ;
}

void QtMIDI::timerEvent(QTimerEvent *)
{
	if(this->timerCounter < 0) return;
	if(this->timerCounter == 0) {
		timerTick();
		return;
	}
	this->timerCounter--;
}

void QtMIDI::timerTick()
{
	int TimerInt = __playNextNode();
	if(TimerInt == -1){
		this->current_play_state = 2;
		emit playStateChanged(2);
		this->changeTimer(false);
	}else if(TimerInt == -2){
		this->current_play_state = 3;
		emit playStateChanged(3);
		this->setTimerInterval(1);
	}else{
		TimerInt = (int)((float)TimerInt/(speed+0.00001));
		this->setTimerInterval(TimerInt);
		this->current_time+=TimerInt;
		emit currentTimeChanged(current_time);
	}
}

QtMIDI::QtMIDI(QObject *parent)
	: QObject(parent)
{
	this->device = new QtMIDIDevice();
	this->playdata = new QtMIDIData();
	this->timerID = this->startTimer(100,Qt::PreciseTimer);
}

QtMIDI::~QtMIDI()
{
	this->killTimer(this->timerID);
	delete this->device;
	delete this->playdata;
}

quint64 QtMIDI::TotalTime()
{
	return 0;
}

quint64 QtMIDI::CurrentTime()
{
	return this->current_time;
}

int QtMIDI::CurrentPosition()
{
	return this->current;
}

int QtMIDI::playState()
{
	return this->current_play_state;
}

void QtMIDI::setCurrentPosition()
{

}

void QtMIDI::setCurrentTime(bool floor)
{

}

void QtMIDI::startAChord(quint8 chord, MIDI::Timbre timbre)
{
	this->device->send(MIDI_CTL_CHG_TIMBRE|(quint32)(timbre<<8));
	MIDI_Node node;
	node.key = chord;
	node.volume = 64;
	node.ctl = MIDI_CTL_START;
	node.zero = 0x00;
	this->device->send(node.word);
}

void QtMIDI::stopAChord(quint8 chord)
{
	MIDI_Node node;
	node.key = chord;
	node.volume = 64;
	node.ctl = MIDI_CTL_STOP;
	node.zero = 0x00;
	this->device->send(node.word);
}

void QtMIDI::play(int pos)
{
	if(pos >= 0){
		this->current=pos;
		this->current_time = this->CurrentTime();
		emit currentTimeChanged(this->current_time);
		this->current_play_state = 1;
		emit playStateChanged(1);
		this->changeTimer(true);
		return;
	}
	if(current_play_state==1)return;
	this->current_play_state = 1;
	emit playStateChanged(1);
	this->changeTimer(true);
}

void QtMIDI::pause()
{
	if(current_play_state == 1){
		this->changeTimer(false);
		this->device->clear();
		current_play_state = 0;
		emit playStateChanged(0);
	}
}

void QtMIDI::stop()
{
	if(current_play_state != 2){
		this->changeTimer(false);
		this->device->clear();
		current = 0;
		current_time = 0;
		current_play_state = 2;
		emit playStateChanged(2);
	}
}





QtMIDIDevice::QtMIDIDevice()
{
	int flag = midiOutOpen(&this->device,-1,0,0,0);
	if (flag != MMSYSERR_NOERROR) {
		qDebug()<<"Error opening MIDI Output.\n";
		wchar_t err[120] = {0};
		midiInGetErrorTextW(flag,err,120);
		qDebug()<<err;
		this->device = (HMIDIOUT)-1;
	}
}

QtMIDIDevice::~QtMIDIDevice()
{
	if(this->device != (HMIDIOUT)-1){
		midiOutReset(device);
		midiOutClose(device);
	}
}

void QtMIDIDevice::send(quint32 word)
{
	if(this->device == (HMIDIOUT)-1){
		qDebug()<<"Warning: MIDI Output is not open.\n";
		return;
	}
	int flag = midiOutShortMsg(this->device, word);
	if(flag != MMSYSERR_NOERROR) {
		qDebug()<<"Warning: MIDI Output is not open.\n";
	}
}

void QtMIDIDevice::clear()
{
	if(this->device != (HMIDIOUT)-1){
		midiOutReset(device);
	}
}
