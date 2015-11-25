/*	File:		TextFile.r	Contains:	Text file support for simple text application	Version:	GX 1.2 or later** Copyright 1993, 1995-1996 Apple Computer. All rights reserved.****	You may incorporate this sample code into your applications without**	restriction, though the sample code has been provided "AS IS" and the**	responsibility for its operation is 100% yours.  However, what you are**	not permitted to do is to redistribute the source as "DSC Sample Code"**	after having made changes. If you're going to re-distribute the source,**	we require that you make it clear in the source that the code was**	descended from Apple Sample Code, but that you've made changes.*/#include "TextFile.h"resource 'STR#' (kTextStrings, purgeable) {	{	SOUNDSPEAKSELECTIONITEM;	SOUNDSPEAKALLITEM;		TEXTSTATIONERY;	TEXTSTATIONERYSELECTED;	TEXTDOCUMENT;	TEXTDOCUMENTSELECTED;		TEXTPICTMARKER1;	TEXTPICTMARKER2;	};};resource 'DLOG' (kTextSaveAsDialogID) {	{0, 0, 238, 344},	dBoxProc,	invisible,	noGoAway,	0x0,	kTextSaveAsDialogID,	"",	alertPositionMainScreen};resource 'dctb' (kTextSaveAsDialogID, purgeable) {	 {};};resource 'DITL' (kTextSaveAsDialogID) {	{	/* array DITLarray: 17 elements */		/* [1] */		{161, 252, 181, 332},		Button {			enabled,			TEXTSAVEBUTTON		},		/* [2] */		{130, 252, 150, 332},		Button {			enabled,			TEXTCANCELBUTTON		},		/* [3] */		{-1, -1, -1, -1},		HelpItem {			disabled,			HMScanhdlg {				-6043			}		},		/* [4] */		{8, 235, 24, 337},		UserItem {			enabled		},		/* [5] */		{32, 252, 52, 332},		Button {			enabled,			TEXTEJECTBUTTON		},		/* [6] */		{60, 252, 80, 332},		Button {			enabled,			TEXTDESKTOPBUTTON		},		/* [7] */		{29, 12, 175, 230},		UserItem {			enabled		},		/* [8] */		{7, 12, 26, 230},		UserItem {			enabled		},		/* [9] */		{117, 250, 118, 334},		Picture {			disabled,			11		},		/* [10] */		{209, 15, 225, 211},		EditText {			enabled,			""		},		/* [11] */		{188, 15, 204, 211},		StaticText {			disabled,			TEXTSAVEPROMPT		},		/* [12] */		{87, 252, 107, 332},		UserItem {			disabled		},		/* [13] */		{-2, -2, -2, -2},		HelpItem {			disabled,			HMScanhdlg {				kTextSaveAsDialogID			}		},		/* [14] */		{196, 232, 228, 280},		RadioButton {			enabled,			""		},		/* [15] */		{196, 288, 228, 336},		RadioButton {			enabled,			""		},		/* [16] */		{196, 248, 228, 280},		UserItem {			enabled,		},		/* [17] */		{196, 304, 228, 336},		UserItem {			enabled,		}	}};// this is extra help for our save as dialogresource 'hdlg' (kTextSaveAsDialogID) {	HelpMgrVersion,							/* Help Version */	13,										/* offset to first DITL */	0,										/* options */	0,										/* theProc */	0,										/* variant */	HMSkipItem {},	{		HMStringResItem {			{0,0},			{0,0,0,0},			kTextStrings, iDocumentHelp,			kTextStrings, 0,			kTextStrings, iDocumentSelectedHelp,			kTextStrings, 0		},		HMStringResItem {			{0,0},			{0,0,0,0},			kTextStrings, iStationeryHelp,			kTextStrings, 0,			kTextStrings, iStationerySelectedHelp,			kTextStrings, 0		},	}};