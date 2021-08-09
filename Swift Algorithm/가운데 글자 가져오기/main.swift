//
//  main.swift
//  가운데 글자 가져오기
//
//  Created by Ha Neul Iee on 2021/08/09.
//

import Foundation

func solution(_ s:String) -> String {
    
    if s.count % 2 == 0 {
        return String(Array(s)[s.count/2-1...s.count])
    }
    return String(Array(s)[s.count/2])
}

