/**
 Copyright (c) 2014-present, Facebook, Inc.
 All rights reserved.
 
 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#import "FBTweak.h"


/**
 @abstract Implementation works by storing the array in the tweak's `stepValue`. The values of the array are
   exposed through the Tweaks UI through the value's `description`.
 @discussion Array tweaks contain objects which cannot be evaluated at compile-time like most
   other tweaks. As a result, the tweak must be accessed once before it will be available in the
   Tweaks UI. Depending on your use-case, an option for this can be to register array tweaks
   from a class's `+initialize` method. This will ensure that the tweak is registered immediately on
   application launch, and the tweak can be accessed later to retrieve the current value.
 */
@interface FBTweak (Array)

/**
 @abstract The array contained by the tweak.
 @discussion The current and default values of the tweak contain an item in this array.
 */
@property (nonatomic, copy, readwrite) NSArray *arrayValue;

/**
 @abstract Indicates whether the tweak instance represents an array tweak.
 @return YES if the instance represents an array tweak.
 */
- (BOOL)isArray;

@end


/**
 @abstract Loads an array tweak defined inline.
 @return A {@ref FBTweak} for the array tweak.
 */
FBTweak *FBArrayTweak(NSString *categoryName, NSString *collectionName, NSString *tweakName, NSArray *array, id defaultValue);

/**
 @abstract Loads the array's value of an array tweak inine.
 @return The array's value of the tweak. If the current value is nil, the default value will be 
   returned.
 */
FBTweakValue FBArrayTweakValue(NSString *categoryName, NSString *collectionName, NSString *tweakName, NSArray *array, id defaultValue);