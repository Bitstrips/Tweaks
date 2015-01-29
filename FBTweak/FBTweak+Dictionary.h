/**
 Copyright (c) 2014-present, Facebook, Inc.
 All rights reserved.
 
 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#import "FBTweak.h"

/**
 @abstract Implementation works by storing the dictionary in the tweak's `stepValue`.
 @discussion Dictionary tweaks contain objects which cannot be evaluated at compile-time like most
   other tweaks. As a result, the tweak must be accessed once before it will be available in the 
   Tweaks UI. Depending on your use-case, an option for this can be to register dictionary tweaks
   from a class's `+initialize` method. This will ensure that the tweak is registered immediately on
   application launch, and the tweak can be accessed later to retrieve the current value.
 */
@interface FBTweak (Dictionary)

/**
 @abstract The keys of dictionary contained in the tweak.
 @discussion Array containing string values for each of the keys in the dictionary.
 */
@property (nonatomic, copy, readonly) NSArray *allKeys;

/**
 @abstract The dictionary contained by the tweak.
 @discussion The current and default values of the tweak represent a key in
   this dictionary.
 */
@property (nonatomic, copy, readwrite) NSDictionary *dictionaryValue;

/**
 @abstract Indicates whether the tweak instance represents a dictionary tweak.
 @return YES if the instance represents a dictionary tweak.
 */
- (BOOL)isDictionary;

@end


/**
 @abstract Loads a dictionary tweak defined inline.
 @return A {@ref FBTweak} for the dictionary tweak.
 */
FBTweak *FBDictionaryTweak(NSString *categoryName, NSString *collectionName, NSString *tweakName, NSDictionary *dictionary, NSString *defaultKey);

/**
 @abstract Loads the key of a dictionary tweak inine.
 @param dictionary A dictionary with string values for keys.
 @return The current string key for the tweak, or the default key if none is set.
 */
NSString *FBDictionaryTweakValue(NSString *categoryName, NSString *collectionName, NSString *tweakName, NSDictionary *dictionary, NSString *defaultKey);

/**
 @abstract Loads the dictionary's value associated with the key of a dictionary tweak inine.
 @return The dictionary's value associated with the key for the tweak. If the current key is nil,
   the value associated with the default key will be returned.
 */
FBTweakValue FBDictionaryTweakValueForKey(NSString *categoryName, NSString *collectionName, NSString *tweakName, NSDictionary *dictionary, NSString *defaultKey);