//////////////	File:		VRSpeech.h////	Contains:	Speech recognition support for QuickTime VR movies.////	Written by:	Tim Monroe////	Copyright:	� 1996 by Apple Computer, Inc., all rights reserved.////	Change History (most recent first):////	   <1>	 	12/05/96	rtm		ported earlier speech recognition support functions to VRShell//	   //////////////////////// header files////////////#ifndef __APPLEEVENTS__#include <AppleEvents.h>#endif#ifndef __FIXMATH__#include <FixMath.h>#endif#ifndef __RESOURCES__#include <Resources.h>#endif#ifndef __SPEECHRECOGNITION__#include <SpeechRecognition.h>#endif#ifndef __SPEECHSYNTHESIS__#include <SpeechSynthesis.h>#endif#ifndef __QUICKTIMEVR__#include <QuickTimeVR.h>#endif#ifndef __TIMER__#include <Timer.h>#endif#ifndef _STDLIB_H#include <stdlib.h>#endif#ifndef __QTUtilities__#include "QTUtilities.h"#endif#ifndef __QTVRUtilities__#include "QTVRUtilities.h"#endif////////////// constants////////////#define FloatToFixed(a) 			((Fixed)((float)(a) * fixed1))#define VRPi 						(3.1415926535898)#define VRDegreesToRadians(a) 		((a) * VRPi / 180.0)#define VRRadiansToDegrees(a) 		((a) * 180.0 / VRPi)#define kLMResourceType				'LMDL'#define kLMResourceID				129#define kSpinMillisecsDelay			25				//empirically determined////////////// data types////////////// an expanded Time Manager record// we use this to manage the spinning aroundtypedef struct MyTMTask {	TMTask			theTMTask;	long			theSpinDir;	long			theSpinAmt;	long			theSpinDelay;	QTVRInstance	theInstance;} MyTMTask, *MyTMTaskPtr;////////////// function prototypes////////////void				VRSpeech_Init (void);void				VRSpeech_Stop (void);PASCAL_RTN OSErr	VRSpeech_HandleSpeechBegunAppleEvent (const AppleEvent *theMessage, AppleEvent *theReply, long theRefcon);PASCAL_RTN OSErr	VRSpeech_HandleSpeechDoneAppleEvent (const AppleEvent *theMessage, AppleEvent *theReply, long theRefcon);OSErr				VRSpeech_ReadLanguageModelsFromResource (void);Boolean				VRSpeech_GoDirByDegrees (QTVRInstance theInstance, long theDir, long theAmt);Boolean				VRSpeech_GoDirByRadians (QTVRInstance theInstance, long theDir, long theAmt);void				VRSpeech_ZoomInOrOut(QTVRInstance theInstance, long theDir);PASCAL_RTN void		VRSpeech_SpinTask (TMTaskPtr theTaskPtr);void				VRSpeech_DoEventLoopSpinCheck (void);Boolean				VRSpeech_IsSpinning (void);void				VRSpeech_StartSpinning (QTVRInstance theInstance, long theDir);void				VRSpeech_StopSpinning (void);void				VRSpeech_InstallSpeechFeedbackRoutine (QTVRInstance theInstance);PASCAL_RTN void		VRSpeech_SpeechFeedbackRoutine (QTVRInstance theInstance, QTVRInterceptPtr theMsg, SInt32 theRefcon, Boolean *theCancel);PASCAL_RTN OSErr	VRSpeech_SpeakNameOfNode (QTVRInstance theInstance, UInt32 nodeID, SInt32 theRefcon);