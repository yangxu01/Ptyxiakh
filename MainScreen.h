/*
 * MainScreen.h
 *
 *  Created on: 28 Ιουλ 2012
 *      Author: Σταμάτης
 */

#ifndef MAINSCREEN_H_
#define MAINSCREEN_H_

#include "BrowseScreen/BrowseScreen.h"
#include "HypertextScreen/HypertextScreen.h"
#include "GPS/GPSListener.h"
#include "GPS/GPS.h"
#include "Common/DataStruct.h"
#include "XML/XML.h"
#include "LogInScreen/LogIn.h"
#include "SoundInterface/Sound.h"
#include "PreviewScreen/PreviewScreen.h"


#include <maapi.h>
#include <MAUtil/util.h>
#include <MAFS/File.h>
#include <MAP/DateTime.h>
#include <MAUI/Screen.h>

// Include all the wrappers.
#include <NativeUI/Widgets.h>

using namespace NativeUI;


class MainScreen: public ButtonListener, public StackScreen, public EditBoxListener,
				  public StackScreenListener, public GPSListener
{
	public:
		MainScreen();
		~MainScreen();
		Screen* getScreen();
		Option* getOptScr();
		void callPreviewScreen(int Screen);
		PreviewScreen* getPreviewScreen();
		virtual void pop();


	private:
		virtual void buttonClicked(Widget *button);
		virtual void editBoxEditingDidBegin(EditBox *editBox);
		virtual void gpsEnd(GPS* gpsWidget, MALocation loc, MALocation old_loc);
		virtual void editBoxEditingDidEnd(EditBox *editBox);
		virtual void editBoxReturn(EditBox *editBox);
		virtual void stackScreenScreenPopped(StackScreen *stackScreen, Screen *fromScreen, Screen *toScreen);
		//virtual void gpsDataReceived(GPS* gpsWidget, MALocation loc);
		virtual void hasMoved(GPS* gpsWidget, MALocation loc, MALocation old_loc);
		virtual void firstPoint(GPS* gpsWidget, MALocation);
		void updateList(MALocation loc);
		virtual void compassOrientationChanged(GPS* gpsWidget, int azimuth);
		void deleteTop(int num);

	//Enum
	private:
		enum {Start ,Options, Hyper};
		//enum {NORTH = 1, SOUTH, WEST, EAST, WRONG};

	private:
		Option *optionScreen;
		HypertextScreen *hyperScreen;
		LogIn *logInScreen;
		PreviewScreen *previewScreen;
		NativeUI::VerticalLayout *_Layout;
		NativeUI::ListView *_ListView;
		//MAUtil::Vector<ListViewItem*> *_ListViewItems;
		NativeUI::Button *_Button[3];
		NativeUI::EditBox *_EditBox;
		NativeUI::GPS *_GPS;
		Screen *screen;
		XML *xml;
		Data loc_data;
		bool metersSeconds;
		//bool mapLoaded;
};


#endif /* MAINSCREEN_H_ */
