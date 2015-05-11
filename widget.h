#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QEvent>
#include <QKeyEvent>
#include <MIDI/QtMIDI.h>
#include <QDebug>
class Widget : public QWidget
{
	Q_OBJECT

	QtMIDI *midi;
public:
	Widget(QWidget *parent = 0);
	~Widget();

public:

	void keyPressEvent(QKeyEvent *e);

	void keyReleaseEvent(QKeyEvent *e);

};

#endif // WIDGET_H

