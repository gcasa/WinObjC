/*
 * Copyright (c) 2011, The Iconfactory. All rights reserved.
 *
 * Copyright (c) 2015 Microsoft Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of The Iconfactory nor the names of its contributors may
 *    be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE ICONFACTORY BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKitExport.h>

UIKIT_EXPORT NSString* const UIDeviceOrientationDidChangeNotification;

typedef enum {
    UIDeviceOrientationUnknown,
    UIDeviceOrientationPortrait,
    UIDeviceOrientationPortraitUpsideDown,
    UIDeviceOrientationLandscapeLeft,
    UIDeviceOrientationLandscapeRight,
    UIDeviceOrientationFaceUp,
    UIDeviceOrientationFaceDown
} UIDeviceOrientation;

typedef enum {
    UIUserInterfaceIdiomPhone,
    UIUserInterfaceIdiomPad,
    UIUserInterfaceIdiomDesktop,
} UIUserInterfaceIdiom;

enum {
    UIDeviceBatteryStateUnknown,
    UIDeviceBatteryStateUnplugged,
    UIDeviceBatteryStateCharging,
    UIDeviceBatteryStateFull,
};
typedef uint32_t UIDeviceBatteryState;

#define UI_USER_INTERFACE_IDIOM()                                                                                                  \
    ([[UIDevice currentDevice] respondsToSelector:@selector(userInterfaceIdiom)] ? [[UIDevice currentDevice] userInterfaceIdiom] : \
                                                                                   UIUserInterfaceIdiomPhone)

#define UIDeviceOrientationIsPortrait(orientation) \
    ((orientation) == UIDeviceOrientationPortrait || (orientation) == UIDeviceOrientationPortraitUpsideDown)

#define UIDeviceOrientationIsLandscape(orientation) \
    ((orientation) == UIDeviceOrientationLandscapeLeft || (orientation) == UIDeviceOrientationLandscapeRight)

UIKIT_EXPORT_CLASS
@interface UIDevice : NSObject {
    UIDeviceOrientation _curOrientation;
    int _isGeneratingEvents;
    bool _batteryMonitoringEnabled;
}

+ (UIDevice*)currentDevice;

@property (nonatomic, readonly, retain) NSString* name;
@property (nonatomic, readonly) UIUserInterfaceIdiom userInterfaceIdiom; // always returns UIUserInterfaceIdiomDesktop
@property (nonatomic, readonly) UIDeviceOrientation orientation; // always returns UIDeviceOrientationPortrait
@property (nonatomic, readonly, getter=isMultitaskingSupported) BOOL multitaskingSupported; // always returns YES
@property (nonatomic, readonly, retain) NSString* systemName;
@property (nonatomic, retain) NSString* systemVersion;
@property (nonatomic, readonly, retain) NSString* model;
@property (nonatomic, readonly, getter=isGeneratingDeviceOrientationNotifications)
    BOOL generatesDeviceOrientationNotifications; // aways returns NO
@property (nonatomic, readonly, retain) NSString* uniqueIdentifier;
@property (nonatomic, readonly, retain) NSUUID* identifierForVendor;
@property (nonatomic, readonly) float batteryLevel;
@property (nonatomic, readonly) UIDeviceBatteryState batteryState;
@property (nonatomic, getter=isBatteryMonitoringEnabled) BOOL batteryMonitoringEnabled;
- (void)beginGeneratingDeviceOrientationNotifications; // no effect
- (void)endGeneratingDeviceOrientationNotifications; // no effect

@end

@interface UIDevice (UIDeviceStarboardAdditions)
@property (nonatomic, readonly, retain) NSString* nativePlatformName;
@property (nonatomic, readonly, retain) NSString* nativeManufacturer;
@property (nonatomic, readonly, retain) NSString* nativeModel;
@property (nonatomic, readonly, retain) NSString* nativeProductName;
@property (nonatomic, readonly, retain) NSString* nativeSerialNo;
@property (nonatomic, readonly, retain) NSString* nativeCarrier;
@property (nonatomic, readonly, retain) NSString* nativeOSVersion;

@property (nonatomic, readonly) int nativeResolutionWidth;
@property (nonatomic, readonly) int nativeResolutionHeight;

@property (nonatomic, readonly) float screenPhysicalWidth;
@property (nonatomic, readonly) float screenPhysicalHeight;

+ (uint64_t)_deviceTotalMemory;
@end
