/***	File:		AboutBox.c****	Contains:	About Box support for SimpleText**** Copyright 1993-1999 Apple Computer. All rights reserved.****	You may incorporate this sample code into your applications without**	restriction, though the sample code has been provided "AS IS" and the**	responsibility for its operation is 100% yours.  However, what you are**	not permitted to do is to redistribute the source as "DSC Sample Code"**	after having made changes. If you're going to re-distribute the source,**	we require that you make it clear in the source that the code was**	descended from Apple Sample Code, but that you've made changes.*/#include "MacIncludes.h"#include "AboutBox.h"// --------------------------------------------------------------------------------------------------------------// INTERNAL ROUTINES// --------------------------------------------------------------------------------------------------------------static void DrawCenteredStringAt(Str255 theString, short yLocation){	Rect	portRect = qd.thePort->portRect;		MoveTo(portRect.left + ((portRect.right-portRect.left) >> 1) -							(StringWidth(theString) >> 1), yLocation);	DrawString(theString);	} // DrawCenteredStringAt// --------------------------------------------------------------------------------------------------------------// OOP INTERFACE ROUTINES// --------------------------------------------------------------------------------------------------------------static OSErr	AboutUpdateWindow(WindowRef pWindow, WindowDataPtr pData){#pragma unused (pData)	Str255		theString;		// type style for application name	TextFont(systemFont);	TextSize(12);		// name of application	GetIndString(theString, kAboutStrings, 1);	DrawCenteredStringAt(theString, 32);		// type style for all others	TextFont(applFont);	TextSize(9);		// author names	GetIndString(theString, kAboutStrings, 2);	DrawCenteredStringAt(theString, 50);	GetIndString(theString, kAboutStrings, 3);	DrawCenteredStringAt(theString, 65);	GetIndString(theString, kAboutStrings, 4);	DrawCenteredStringAt(theString, 80);		// copyright, on the left	GetIndString(theString, kAboutStrings, 5);	MoveTo(10, 105);	DrawString(theString);		// version, on the right	GetIndString(theString, kAboutStrings, 6);	MoveTo((GetWindowPort(pWindow)->portRect.right - 10) - StringWidth(theString), 105);	DrawString(theString);		return noErr;	} // AboutUpdateWindow// --------------------------------------------------------------------------------------------------------------static OSErr	AboutGetBalloon(WindowRef pWindow, WindowDataPtr pData, 		Point *localMouse, short * returnedBalloonIndex, Rect *returnedRectangle){#pragma unused (pWindow, pData, localMouse, returnedRectangle)	*returnedBalloonIndex = iNoBalloon;		return noErr;	} // AboutGetBalloon// --------------------------------------------------------------------------------------------------------------static OSErr	AboutKeyEvent(WindowRef pWindow, WindowDataPtr pData, EventRecord *pEvent, Boolean isMotionKey){	#pragma unused(pWindow, pData, pEvent, isMotionKey)	return noErr;} // AboutKeyEvent// --------------------------------------------------------------------------------------------------------------static OSErr	AboutMakeWindow(WindowRef pWindow, WindowDataPtr pData){#pragma unused (pWindow)	pData->pUpdateWindow = (UpdateWindowProc) AboutUpdateWindow;	pData->pGetBalloon	 = (GetBalloonProc) AboutGetBalloon;	pData->pKeyEvent	 = (KeyEventProc) AboutKeyEvent;	return noErr;	} // AboutMakeWindow// --------------------------------------------------------------------------------------------------------------OSErr	AboutPreflightWindow(PreflightPtr pPreflightData){	pPreflightData->resourceID 			= kAboutWindowID;	pPreflightData->continueWithOpen 	= true;	pPreflightData->makeProcPtr 		= (MakeWindowProc) AboutMakeWindow;		return noErr;	} // AboutPreflightWindow// --------------------------------------------------------------------------------------------------------------void AboutGetFileTypes(OSType * pFileTypes, OSType * pDocumentTypes, short * numTypes){#pragma unused (pFileTypes, pDocumentTypes, numTypes)} // AboutGetFileTypes