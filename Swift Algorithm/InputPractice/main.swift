//
//  main.swift
//  InputPractice
//
//  Created by Ha Neul Iee on 2021/08/09.
//

import Foundation

/* 1, 2, 3, 4, 5 -> Int 배열로 변환하기
 
let intArr = readLine()!.split(separator: " ").map { Int($0)! }
print(intArr[0])
*/


/* 1, 2, 3, 4, 5 -> String 배열로 변환하기

let stringArr = readLine()!.split(separator: " ")
print(stringArr)
 
 // closure 방식의 split
let stringArr = readLine()!.split { $0 == " " }
 
*/


/* 12345 -> Int 배열로 반환하기, Array(readLine())이 배열에 반환하는 값은 Character 이다.
            따라서 String으로 변환 후 Int로 바꿔주기
            주의!! Character은 Int로 바로 변환할 수 없다.
 
let intArr = Array(readLine()!).map { Int(String($0))! }
print(intArr)
*/


/* Swift의 자료구조 3대장?
    
 Array, Set, Dictionary
 Heap, Stack, Queue를 지원하지않음...
*/


/* 고차함수 연습
 
 reversed(), sort(), sorted(), enumerated(), reduce(into:), map(), compactMap(),
 split(separator:), components(separatedBy:)
*/


/* 크기가 정해진 배열

var threeDoubles = [Int](repeating: 0, count: 3)        // [0, 0, 0]
var threeDoubles2 = Array(repeating: 0, count: 3)       // [0, 0, 0]
var threeDoubles4 = [String](repeating: "A", count: 3)  // ["A", "A", "A"]
 */


/* 배열에 값 추가
 
var a: [Int] = [1, 2, 3, 4]
a.append(5)
a += [6, 7, 8]
a.append(contentsOf: stride(from: 5, to: 10, by: 1))        // 5~9
a.append(contentsOf: stride(from: 5, through: 10, by: 1))   // 5~10
*/


/* 크기가 정해진 이차원 배열

var arr: [[Int]] = Array(repeating: Array(repeating: 0, count: 5), count: 3)
var arr2 = [[Int]](repeating: Array(repeating: 0, count: 5), count: 3)
var arr3 = [[String]](repeating: Array(repeating: "A", count: 5), count: 3)
*/


/* 배열 특정 범위 꺼내기
 
var array: [Int] = [1, 5, 2, 6, 3, 7, 4]
array[0...2]
*/


/* 배열 index로 접근 indices

let s = "hello!"
for index in s.indices {
    print("\(s[index])", terminator: "")
}
*/


/* firstIndex 활용
 
let greeting = "Hello, world!"
let index = greeting.firstIndex(of: ",")!
let beginning = greeting[..<index]
// beginning is "Hello"
print(beginning)

// Convert the result to a String for long-term storage.
let newString = String(beginning)
print(newString)
*/
