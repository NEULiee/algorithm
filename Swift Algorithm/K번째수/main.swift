//
//  main.swift
//  프로그래머스 K번째수
//
//  Created by Ha Neul Iee on 2021/08/09.
//
//  https://docs.swift.org/swift-book/LanguageGuide/CollectionTypes.html

import Foundation

func solution(_ array:[Int], _ commands:[[Int]]) -> [Int] {
    var res: [Int] = []
    
    for command in commands {
        let i = command[0]-1
        let j = command[1]-1
        let k = command[2]-1
        
        let num = Array(array[i...j]).sorted()[k]
        res.append(num)
    }
    
    return res

}
