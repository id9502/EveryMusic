#include "widget.h"

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	this->midi = new QtMIDI(this);
}

Widget::~Widget()
{
	delete this->midi;
	this->setFocusPolicy(Qt::StrongFocus);
}

void Widget::keyPressEvent(QKeyEvent *e)
{
	if(e->isAutoRepeat()) return;
	switch(e->key()){
	case 'A':
		midi->startAChord(60);
		break;
	case 'W':
		midi->startAChord(61);
		break;
	case 'S':
		midi->startAChord(62);
		break;
	case 'E':
		midi->startAChord(63);
		break;
	case 'D':
		midi->startAChord(64);
		break;
	case 'F':
		midi->startAChord(65);
		break;
	case 'T':
		midi->startAChord(66);
		break;
	case 'G':
		midi->startAChord(67);
		break;
	case 'Y':
		midi->startAChord(68);
		break;
	case 'H':
		midi->startAChord(69);
		break;
	case 'U':
		midi->startAChord(70);
		break;
	case 'J':
		midi->startAChord(71);
		break;
	case 'K':
		midi->startAChord(72);
		break;
	case 'O':
		midi->startAChord(73);
		break;
	case 'L':
		midi->startAChord(74);
		break;
	default:
		qDebug()<<(char)e->key();
		break;
	}
}

void Widget::keyReleaseEvent(QKeyEvent *e)
{
	switch(e->key()){
	case 'A':
		midi->stopAChord(60);
		break;
	case 'W':
		midi->stopAChord(61);
		break;
	case 'S':
		midi->stopAChord(62);
		break;
	case 'E':
		midi->stopAChord(63);
		break;
	case 'D':
		midi->stopAChord(64);
		break;
	case 'F':
		midi->stopAChord(65);
		break;
	case 'T':
		midi->stopAChord(66);
		break;
	case 'G':
		midi->stopAChord(67);
		break;
	case 'Y':
		midi->stopAChord(68);
		break;
	case 'H':
		midi->stopAChord(69);
		break;
	case 'U':
		midi->stopAChord(70);
		break;
	case 'J':
		midi->stopAChord(71);
		break;
	case 'K':
		midi->stopAChord(72);
		break;
	case 'O':
		midi->stopAChord(73);
		break;
	case 'L':
		midi->stopAChord(74);
		break;
	default:
		qDebug()<<(char)e->key();
		break;
	}
}
