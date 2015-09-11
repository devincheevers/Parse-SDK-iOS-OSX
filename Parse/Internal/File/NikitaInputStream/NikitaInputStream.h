/**
 * Copyright (c) 2015-present, Parse, LLC.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @abstract Why? Because Nikita.
 @discussion Actually, this does have some practical use. When downloading a file stream via 
 `-[PFFile getDataDownloadStreamInBackground]`, we need to be able to read and write to the same file on disk
 concurrently.
 
 NSInputStream closes itself as soon as it hits EOF, so this class wraps an underlying NSInputStream and stops the 
 stream from closing until after writing has finished.
 */
@interface NikitaInputStream : NSProxy

- (instancetype)initWithFileAtPath:(NSString *)path;

- (void)stopBlocking;

@end

NS_ASSUME_NONNULL_END
