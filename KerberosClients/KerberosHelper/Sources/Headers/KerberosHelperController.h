/*
 * KerberosHelperController.h
 *
 * $Header$
 *
 * Copyright 2006 Massachusetts Institute of Technology.
 * All Rights Reserved.
 *
 * Export of this software from the United States of America may
 * require a specific license from the United States Government.
 * It is the responsibility of any person or organization contemplating
 * export to obtain such a license before exporting.
 * 
 * WITHIN THAT CONSTRAINT, permission to use, copy, modify, and
 * distribute this software and its documentation for any purpose and
 * without fee is hereby granted, provided that the above copyright
 * notice appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation, and that
 * the name of M.I.T. not be used in advertising or publicity pertaining
 * to distribution of the software without specific, written prior
 * permission.  Furthermore if you modify this software you must label
 * your software as modified software and not distribute it in such a
 * fashion that it might be confused with the original M.I.T. software.
 * M.I.T. makes no representations about the suitability of
 * this software for any purpose.  It is provided "as is" without express
 * or implied warranty.
 */

#import "KerberosCacheCollection.h"


@interface KerberosHelperController : NSObject {
	IBOutlet NSMenu *statusMenu;
	IBOutlet NSMenu *statusModesMenu;
    IBOutlet NSMenuItem *statusNewTicketsMenuItem;
    IBOutlet NSMenuItem *statusRenewTicketsMenuItem;
    IBOutlet NSMenuItem *statusValidateTicketsMenuItem;
    IBOutlet NSMenuItem *statusDestroyTicketsMenuItem;
    IBOutlet NSMenuItem *statusChangePasswordMenuItem;
    IBOutlet NSMenuItem *statusSeparatorItem;
	IBOutlet NSMenuItem *statusOpenKerberosAppMenuItem;
    
    KerberosCacheCollection *cacheCollection;
    
	cc_context_t context;
	
	cc_time_t lastChangeTime;
	
	NSTimer *updateTimer;
	NSTimer *minuteTimer;
	
	NSStatusItem *menuBarStatusItem;
}

- (id) init;
- (void) dealloc;

- (IBAction) menuBarStatusItemModeDidChange: (id) sender;
- (IBAction) openKerberosApplication: (id) sender;

- (IBAction) getTickets: (id) sender;
- (IBAction) changePasswordForActiveUser: (id) sender;
- (IBAction) destroyTicketsForActiveUser: (id) sender;
- (IBAction) renewTicketsForActiveUser: (id) sender;
- (IBAction) validateTicketsForActiveUser: (id) sender;
- (IBAction) changeActiveUser: (id) sender;

- (void) awakeFromNib;

- (void) applicationWillTerminate: (NSNotification *) notification;
- (void) cacheCollectionDidChange: (NSNotification *) notification;

- (void) updateStatusItemIfNeeded;
- (void) updateStatusItem;

- (BOOL) haveDefaultCache;
- (BOOL) defaultCacheNeedsValidation;

- (void) addMenuBarStatusItem;
- (NSString *) menuBarStatusItemTitleForCache: (KerberosCache *) cache;
- (NSString *) menuBarStatusItemModeString;

- (int) modePreference;
- (void) setModePreference: (int) value;

@end