/*  Problem:
 *
 *Suppose we are given N different types of stickers. 
 Each sticker type has a word on it, 
 for example, we could have 4 sticker types that say “math”, “science”, “english”, and “history” respectively. 
 You would like to spell out the target word “learning” by cutting out individual letters from your collection 
 of stickers and rearranging them. 
 If you are allowed touse more than one sticker of a given type to form the target word, what is the minimum
 number of total stickers you will require? 
 In the example above,one possible optimal solution is: 
   use 1 “math” sticker, 2 “english” stickers, and 1 “history” sticker, for a total of 4 stickers.
 * */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

int helper(unordered_map<string, vector<int> >&strMap, unordered_map<char, vector<string> > &charMap, vector<int> &target, int tLen);

int main(){
    unordered_map<string, vector<int> > strMap;
    unordered_map<char, vector<string> > charMap;
    cout << "input dictionary: (end with 0)" << endl;
    string input;
    vector<string> dict;
    while(1){
        cin >> input;
        if(input[0] == '0') break;
        dict.push_back(input);
    }
    cout << "input target word: " << endl;
    cin >> input;
    // build two maps
    for(string s : dict){
        vector<int> letter(26, 0);
        for(int i = 0; i < s.length(); ++i){
            letter[s[i] - 'a']++;
            if(charMap.find(s[i]) != charMap.end()){
                vector<string> strs = charMap[s[i]];
                if(strs[strs.size() - 1] != s){   
                    strs.push_back(s);
                    charMap[s[i]] = strs;
                }
            }else{
                vector<string> strs;
                strs.push_back(s);
                charMap[s[i]] = strs;
            }
        }
        strMap[s] = letter;
    }
    // build target vector
    vector<int> target(26, 0);
    int tLen = input.length();
    for(int i = 0; i < input.length(); ++i)
        target[input[i] - 'a'] += 1;
    int res = helper(strMap, charMap, target, tLen);
    cout << "the minimum number of sticker is : " << res << endl;
    return 0;
}

int helper(unordered_map<string, vector<int> >&strMap, unordered_map<char, vector<string> > &charMap, vector<int> &target, int tLen){
    if(tLen == 0) return 0;
    int i;
    for(i = 0; i < 26; ++i){
        if(target[i] > 0) break;
    }
    vector<string> strs = charMap[(char)('a' + i)];
    int res = INT_MAX, tmp = 0, sum = 0;
    string s;
    char ch = (char)('a' + i);
    vector<int> v;
    for(i = 0; i < strs.size(); ++i){
        s = strs[i];
        v = strMap[s];
        sum = 0;
        for(int j = 0; j < 26; ++j){
            sum += (target[j] >= 0) ? min(v[j], target[j]) : 0;
            target[j] -= v[j];
        }
        tmp = helper(strMap, charMap, target, tLen - sum);
        res = min(res, tmp);
        for(int j = 0; j < 26; ++j) target[j] += v[j];
    }
    return res + 1;
}
