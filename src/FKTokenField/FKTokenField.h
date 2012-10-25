/*
 
 FKTokenField.h
 FieldKit
 
 Copyright (cc) 2012 Luis Laugga.
 Some rights reserved, all wrongs deserved.
 
 Licensed under a Creative Commons Attribution-ShareAlike 3.0 License;
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://creativecommons.org/licenses/by-sa/3.0/
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" basis,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 
*/

#import "FKTextField.h"

#import "FKTokenFieldDelegate.h"
#import "FKTokenFieldCell.h"

/*!
 @abstract Text Field
 @discussion 
 The text field is a view used for text input.
 It conforms to UITextInput (and UIKeyInput) protocols and also NSCoding
 
 Accessing the 'text' property will return only the current editing string, if any. In order to set the tokens
 the property 'representedObjects' should be used instead.
 */
@interface FKTokenField : FKTextField
{
    NSCharacterSet * _tokenizingCharacterSet; // default is newline
    
    NSTimeInterval _completionDelay; // delay before display completion view
    UIView * _completionSuperview; // host UIView for completion view
    
    NSMutableArray * _tokenFieldCells;
    
    FKTokenStyle _tokenStyle; // FKTokenFieldCell style
}

/*!
 Sets the set of tokenizing characters
 If not set, the default character set will be used
 */
@property(nonatomic, copy) NSCharacterSet * tokenizingCharacterSet;

/*!
 Provide a list of objects being represented by tokens.
 @discussion If the represented object is an instance of NSString the token field uses it as display string, otherwise 
 the delegate can provide a display string via tokenField:displayStringForRepresentedObject:
 */
@property(nonatomic, copy) NSArray * representedObjects;

/*!
 Sets the auto-completion delay before the list of possible completions automatically pops up.  
 Completions are only offered if the delegate implements the completion delegate API.  
 A negative delay will disable completion while a delay of 0.0 will make completion UI presentation immediate.
 */
@property(nonatomic, assign) NSTimeInterval completionDelay;

/*!
 Sets the auto-completion view where the list of possible completions is placed, together with the input field  
 The view should take as much space in the screen as possible, such as a UIViewController root view
 This value can't be nil.
 */
@property(nonatomic, assign) UIView * completionSuperview;

/*!
 Sets the default token style used for each token
 If the delegate implements tokenField:styleForRepresentedObject:, that return value will be used instead
 */
@property(nonatomic, assign) FKTokenStyle tokenStyle;

/*!
 In addition to FKTokenFieldDelagate protocol, the delegate must also conform to FKTextFieldDelegate
 */
@property(nonatomic, assign) id<FKTokenFieldDelegate> delegate;

/*!
 Returns the default completion delay interval in seconds
 */
+ (NSTimeInterval)defaultCompletionDelay;

/*!
 Returns the default set to tokenizing characters
 */
+ (NSCharacterSet *)defaultTokenizingCharacterSet;

@end
