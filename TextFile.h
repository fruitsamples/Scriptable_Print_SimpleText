/*	File:		TextFile.h	Contains:	Text file support for simple text application** Copyright 1993, 1995-1996 Apple Computer. All rights reserved.****	You may incorporate this sample code into your applications without**	restriction, though the sample code has been provided "AS IS" and the**	responsibility for its operation is 100% yours.  However, what you are**	not permitted to do is to redistribute the source as "DSC Sample Code"**	after having made changes. If you're going to re-distribute the source,**	we require that you make it clear in the source that the code was**	descended from Apple Sample Code, but that you've made changes.*/#include "SimpleText.h"#define kTextStrings 			kTextBaseID#define iSpeakSelection				1#define iSpeakAll					2#define iStationeryHelp				3#define iStationerySelectedHelp		4#define iDocumentHelp 				5#define iDocumentSelectedHelp		6#define iPictureMarker1				7#define iPictureMarker2				8#define kTextSaveAsDialogID 	kTextBaseID+1#define iTextDocumentItem		14#define iStationeryDocumentItem	15#define iTextUserItem			16#define iStationeryUserItem		17#define kMaxLength				31*1024#ifndef REZ	struct TextDataRecord		{		WindowDataRecord		w;				Boolean					insideClickLoop;	// inside the click loop		TEClickLoopUPP			docClick;			// old click loop value		TEHandle				hTE;				// text editing area		Handle					soundHandle;		// sound associated with this machine				// undo support items		short					prevCommandID;		Handle					prevText;		Handle					prevStyle;		short					prevLength;		short					prevSelStart;		short					beforeSelStart, beforeSelEnd;		};	typedef struct TextDataRecord TextDataRecord, *TextDataPtr;	#endif