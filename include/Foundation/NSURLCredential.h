/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#import <Foundation/NSObject.h>
#import <Security/Security.h>

typedef NS_ENUM(NSUInteger, NSURLCredentialPersistence) {
    NSURLCredentialPersistenceNone,
    NSURLCredentialPersistenceForSession,
    NSURLCredentialPersistencePermanent,
    NSURLCredentialPersistenceSynchronizable
};

@class NSArray;

FOUNDATION_EXPORT_CLASS
@interface NSURLCredential : NSObject <NSCoding, NSCopying>

+ (NSURLCredential*)credentialWithUser:(NSString*)user password:(NSString*)password persistence:(NSURLCredentialPersistence)persistence;
+ (NSURLCredential*)credentialWithIdentity:(SecIdentityRef)identity
                              certificates:(NSArray*)certArray
                               persistence:(NSURLCredentialPersistence)persistence;
+ (NSURLCredential*)credentialForTrust:(SecTrustRef)trust;
- (BOOL)hasPassword;
@property (readonly, copy) NSString* user;
@property (readonly, copy) NSArray* certificates;
@property (readonly, copy) NSString* password;
@property (readonly) SecIdentityRef identity;
@property (readonly) NSURLCredentialPersistence persistence;

- (instancetype)initWithUser:(NSString*)user password:(NSString*)password persistence:(NSURLCredentialPersistence)persistence;
- (instancetype)initWithIdentity:(SecIdentityRef)identity
                    certificates:(NSArray*)certArray
                     persistence:(NSURLCredentialPersistence)persistence;
- (instancetype)initWithTrust:(SecTrustRef)trust;
- (BOOL)hasPassword;
@end