//
//  ToDoItem.h
//  ToDoList
//
//  Created by Thanh Nguyen Chu on 12.02.15.
//  Copyright (c) 2015 TnSoft. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ToDoItem : NSObject

@property NSString *itemName;
@property BOOL completed;
@property (readonly) NSDate *creationDate;

@end
