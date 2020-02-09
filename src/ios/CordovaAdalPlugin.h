/*******************************************************************************
 * Copyright (c) Microsoft Open Technologies, Inc.
 * All Rights Reserved
 * See License in the project root for license information.
 *
  * MN BEWEB 2018 - Added Intune capability
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>
#import <Cordova/CDVPlugin.h>

#import <ADAL/ADAuthenticationContext.h>
#import "IntuneMAM.h"

// Implements Apache Cordova plugin for Microsoft Azure ADAL
@interface CordovaAdalPlugin : CDVPlugin <IntuneMAMEnrollmentDelegate, IntuneMAMPolicyDelegate>

// AuthenticationContext methods
- (void)createAsync:(CDVInvokedUrlCommand *)command;
- (void)acquireTokenAsync:(CDVInvokedUrlCommand *)command;
- (void)acquireTokenSilentAsync:(CDVInvokedUrlCommand *)command;

// TokenCache methods
- (void)tokenCacheClear:(CDVInvokedUrlCommand *)command;
- (void)tokenCacheReadItems:(CDVInvokedUrlCommand *)command;
- (void)tokenCacheDeleteItem:(CDVInvokedUrlCommand *)command;

+ (ADAuthenticationContext *)getOrCreateAuthContext:(NSString *)authority
                                  validateAuthority:(BOOL)validate;

- (void)setLogger:(CDVInvokedUrlCommand *)command;
- (void)setLogLevel:(CDVInvokedUrlCommand *) command;

 // MN BEWEB 2018 - Added Intune capability
- (void)intuneEnroll:(CDVInvokedUrlCommand *)command;
- (void)intuneUnenroll:(CDVInvokedUrlCommand *)command;

/**
 *  Called when an enrollment request operation is completed.
 * @param status status object containing debug information
 */

- (void)enrollmentRequestWithStatus:(IntuneMAMEnrollmentStatus *)status;

/**
 *  Called when a MAM policy request operation is completed.
 *  @param status status object containing debug information
 */
- (void)policyRequestWithStatus:(IntuneMAMEnrollmentStatus *)status;

/**
 *  Called when a un-enroll request operation is completed.
 *  @Note: when a user is un-enrolled, the user is also de-registered with the SDK
 *  @param status status object containing debug information
 */

- (void)unenrollRequestWithStatus:(IntuneMAMEnrollmentStatus *)status;

@end
