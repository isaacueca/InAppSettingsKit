//
//  IASKSettingsReader.h
//  http://www.inappsettingskit.com
//
//  Copyright (c) 2009:
//  Luc Vandal, Edovia Inc., http://www.edovia.com
//  Ortwin Gentz, FutureTap GmbH, http://www.futuretap.com
//  All rights reserved.
// 
//  It is appreciated but not required that you give credit to Luc Vandal and Ortwin Gentz, 
//  as the original authors of this code. You can give credit in a blog post, a tweet or on 
//  a info page of your app. Also, the original authors appreciate letting them know if you use this code.
//
//  This code is licensed under the BSD license that is available at: http://www.opensource.org/licenses/bsd-license.php
//

#import <Foundation/Foundation.h>

#define kIASKPreferenceSpecifiers             @"PreferenceSpecifiers"
#define kIASKType                             @"Type"
#define kIASKTitle                            @"Title"
#define kIASKKey                              @"Key"
#define kIASKFile                             @"File"
#define kIASKDefaultValue                     @"DefaultValue"
#define kIASKMinimumValue                     @"MinimumValue"
#define kIASKMaximumValue                     @"MaximumValue"
#define kIASKTrueValue                        @"TrueValue"
#define kIASKFalseValue                       @"FalseValue"
#define kIASKIsSecure                         @"IsSecure"
#define KIASKKeyboardType                     @"KeyboardType"
#define kIASKAutocapitalizationType           @"AutocapitalizationType"
#define kIASKAutoCorrectionType               @"AutocorrectionType"
#define kIASKValues                           @"Values"
#define kIASKTitles                           @"Titles"
#define kIASKKeyboardAlphabet                 @"Alphabet"
#define kIASKKeyboardNumbersAndPunctuation    @"NumbersAndPunctuation"
#define kIASKKeyboardNumberPad                @"NumberPad"
#define KIASKKeyboardURL                      @"URL"
#define kIASKKeyboardEmailAddress             @"EmailAddress"
#define kIASKAutoCapNone                      @"None"
#define kIASKAutoCapSentences                 @"Sentences"
#define kIASKAutoCapWords                     @"Words"
#define kIASKAutoCapAllCharacters             @"AllCharacters"
#define kIASKAutoCorrDefault                  @"Default"
#define kIASKAutoCorrNo                       @"No"
#define kIASKAutoCorrYes                      @"Yes"
#define kIASKMinimumValueImage                @"MinimumValueImage"
#define kIASKMaximumValueImage                @"MaximumValueImage"

#define kIASKPSGroupSpecifier                 @"PSGroupSpecifier"
#define kIASKPSToggleSwitchSpecifier          @"PSToggleSwitchSpecifier"
#define kIASKPSMultiValueSpecifier            @"PSMultiValueSpecifier"
#define kIASKPSSliderSpecifier                @"PSSliderSpecifier"
#define kIASKPSTitleValueSpecifier            @"PSTitleValueSpecifier"
#define kIASKPSTextFieldSpecifier             @"PSTextFieldSpecifier"
#define kIASKPSChildPaneSpecifier             @"PSChildPaneSpecifier"
#define kIASKOpenURLSpecifier                 @"IASKOpenURLSpecifier"

#define kIASKBundleFolder                     @"Settings.bundle"
#define kIASKBundleFolderAlt                  @"InAppSettings.bundle"
#define kIASKBundleFilename                   @"Root.plist"

#define kIASKAppSettingChanged                @"kAppSettingChanged"

#define kIASKSectionHeaderIndex               0

#define kIASKSliderNoImagesPadding            11
#define kIASKSliderImagesPadding              43


#define kIASKTableWidth                       320
#define kIASKSpacing                          5
#define kIASKMinLabelWidth                    97
#define kIASKMinValueWidth                    35
#define kIASKPaddingLeft                      9
#define kIASKPaddingRight                     10

#define kIASKLabelFontSize                    17
#define kIASKgrayBlueColor                    [UIColor colorWithRed:0.318 green:0.4 blue:0.569 alpha:1.0]

#ifndef kCFCoreFoundationVersionNumber_iPhoneOS_4_0
#define kCFCoreFoundationVersionNumber_iPhoneOS_4_0 550.32
#endif

#define IASK_IF_IOS4_OR_GREATER(...) \
if (kCFCoreFoundationVersionNumber >= kCFCoreFoundationVersionNumber_iPhoneOS_4_0) \
{ \
__VA_ARGS__ \
}


@class IASKSpecifier;

@interface IASKSettingsReader : NSObject {
    NSString        *_path;
    NSString        *_bundleFolder;
    NSDictionary    *_settingsBundle;
    NSArray         *_dataSource;
    NSBundle        *_bundle;
}

- (id)initWithFile:(NSString*)file;
- (NSInteger)numberOfSections;
- (NSInteger)numberOfRowsForSection:(NSInteger)section;
- (IASKSpecifier*)specifierForIndexPath:(NSIndexPath*)indexPath;
- (IASKSpecifier*)specifierForKey:(NSString*)key;
- (NSString*)titleForSection:(NSInteger)section;
- (NSString*)titleForStringId:(NSString*)stringId;
- (NSString*)bundlePath;
- (NSString*)pathForImageNamed:(NSString*)image;

@property (nonatomic, retain) NSString      *path;
@property (nonatomic, retain) NSString      *bundleFolder;
@property (nonatomic, retain) NSDictionary  *settingsBundle;
@property (nonatomic, retain) NSArray       *dataSource;

@end
