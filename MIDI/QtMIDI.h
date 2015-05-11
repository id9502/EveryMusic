#ifndef QTMIDI_H
#define QTMIDI_H

#include <QObject>
#include <QList>
#include <QString>
#include <MIDI/MIDI_Timbre.h>
#include <QDebug>


#include <windows.h>   /* required before including mmsystem.h */
#include <mmsystem.h>  /* multimedia functions (such as MIDI) for Windows */


enum MIDI_CTL{
	MIDI_CTL_START=0x90,
	MIDI_CTL_CHG_TIMBRE=0xc0,
	MIDI_CTL_STOP=0x80
};

typedef struct {
	union {
		quint32 word;
		struct{
			quint8 ctl;
			quint8 key;
			quint8 volume;
			quint8 zero;
		};
	};
	quint8 timbre=0x00;
	quint8 channel=0x00;
	quint8 effect=0x00;
	quint8 duration_100ms=0x00;
	QFunctionPointer callback=NULL;
} MIDI_Node;

////////////////////////////////////////////////////////////////////////
/// \brief The QtMIDIData class
///
class QtMIDIData{
	QList<MIDI_Node*> *mididata;
	friend class QtMIDI;
	int total_count=0;

public:
	explicit QtMIDIData();
	//QtMIDIData(QString file_name);
	~QtMIDIData();

	void addNewNode(quint8 key, quint8 velocity_100ms=5, quint8 timbre=MIDI::Acoustic_Grand_Piano, quint8 channel=0);
	void addNewNode(QtMIDIData &another);
	void addNewNode(MIDI_Node* newNode);

	MIDI_Node *at(int pos);
};

////////////////////////////////////////////////////////////////////////
/// \brief The QtMIDIDevice class, related to the OS
///
class QtMIDIDevice{
	HMIDIOUT device;    // MIDI device interface for sending MIDI output

public:
	explicit QtMIDIDevice();
	~QtMIDIDevice();

	void send(quint32 word);
	void clear();
};

////////////////////////////////////////////////////////////////////////
/// \brief The QtMIDI class
///
class QtMIDI : QObject
{
	Q_OBJECT

	int current=0;
	float speed=1.0;
	quint64 current_time=0;

	quint8 current_timbre=0;
	int current_play_state=0;

	QtMIDIData *playdata;
	QtMIDIDevice *device;

	int __playNextNode();//when return -1, timer will be disable, -2 will start free-play mode

	int timerCounter=0;
	int timerID=0;
	void setTimerInterval(int t_100ms);
	void changeTimer(bool start=true);

private slots:
	void timerEvent(QTimerEvent *);
	void timerTick();
public:
	explicit QtMIDI(QObject *parent = 0);
	~QtMIDI();

public:
	quint64 TotalTime();
	quint64 CurrentTime();
	int CurrentPosition();
	int playState();
	void setCurrentPosition();
	void setCurrentTime(bool floor=true);

	void startAChord(quint8 chord, MIDI::Timbre timbre = MIDI::Acoustic_Grand_Piano);
	void stopAChord(quint8 chord);

public slots:
	void play(int pos = -1);
	void pause();
	void stop();

signals:
	void currentTimeChanged(quint64 t);
	void endOfMusic();
	void playStateChanged(int newState);
};

#endif // QTMIDI_H
