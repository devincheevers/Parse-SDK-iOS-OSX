/**
 * Copyright (c) 2015-present, Parse, LLC.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <Foundation/Foundation.h>

#import <Parse/PFConstants.h>
#import <Parse/PFUserAuthenticationDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@class BFTask;
@class PFUser;

@interface PFUserAuthenticationController : NSObject

///--------------------------------------
/// @name Authentication Providers
///--------------------------------------

- (void)registerAuthenticationDelegate:(id<PFUserAuthenticationDelegate>)delegate forAuthType:(NSString *)authType;
- (void)unregisterAuthenticationDelegateForAuthType:(NSString *)authType;

- (id<PFUserAuthenticationDelegate>)authenticationDelegateForAuthType:(NSString *)authType;

///--------------------------------------
/// @name Authentication
///--------------------------------------

- (BFTask PF_GENERIC(NSNumber *) *)restoreAuthenticationAsyncWithAuthData:(nullable NSDictionary *)authData
                                       forProviderWithAuthType:(NSString *)authType;
- (BFTask PF_GENERIC(NSNumber *) *)deauthenticateAsyncWithProviderForAuthType:(NSString *)authType;

///--------------------------------------
/// @name Log In
///--------------------------------------

- (BFTask *)logInUserAsyncWithAuthType:(NSString *)authType authData:(NSDictionary *)authData;

@end

NS_ASSUME_NONNULL_END
