#pragma warning(disable : 4996)
#ifdef _MSC_VER
    //  Microsoft 
    #define EXPORT extern "C" __declspec(dllexport)
#elif defined(__GNUC__)
    //Ubuntu
    #define EXPORT  extern "C" __attribute__((visibility("default")))
#else
    //Other
    #define EXPORT
    #pragma warning Unknown dynamic link import/export semantics.

#endif
#pragma region C_CODE
#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <cstdlib>

#include <sstream>

#include <cstring>

#include <algorithm> 

using namespace std;
#ifndef stol
long stol(string& str) {
    long i;
    sscanf(str.c_str(), "%d", &i);
    return i;
}
#endif // !std::stol
struct List {
    std::stringstream value;
    List* next;
};
const char Qt[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMN0PQRSTUVWXYZO123456789+/=";
const char Qt2[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMN0PQRSTUVWXYZO123456789+/=abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMN0PQRSTUVWXYZO123456789+/=";
long id;

#pragma region not_using_func
long QTIndex(char i) {
    const char* ptr = strchr(Qt, i);
    return ptr ? (ptr - (Qt)) : -1;
}
void delete_List(List* start, long i) {
    List* going;
    do {
        going = start;
        (start = start->next);
        delete going;
    } while (--i >= 0);
}
void get_splited(string& a1, string& a2, string find) {

    const long extra_find = find.find("?extra=");
    string finds = find.substr(extra_find + 7);

    const long index = finds.find("#");
    a1 = finds.substr(0, index);
    a2 = finds.substr(index + 1);
}


void next_step_t(const long a, const long n, long& t) {
    t = (n * (a + 1) ^ t + a) % n;
}
long* function_i(const string e, long t) {
    long n = e.length();
    long* i = new long[(long long)n + 1];
    if (n) {
        long a = n;
        for (t = abs(t); a--; ) {
            next_step_t(a, n, t);
            //t = (n * (a + 1) ^ t + a) % n;
            i[a] = t;
        }
    }
    return i;
}

#pragma endregion

string Ytv(string e) {
    std::reverse(e.begin(), e.end());
    return e;
}
string Ytr(string e1, long t) {
    long n;
    const long size = e1.length();
    char* i = const_cast<char*>(e1.c_str());
    for (long a = size; a--; )
        if (~(n = QTIndex(i[a])))
            (i[a] = Qt2[n - t]);
    return e1;
}
string Yts(string e1, const long t) {
    const long n = e1.length();
    if (n) {
        long* i = function_i(e1, t);
        char* e = const_cast<char*>(e1.c_str());
        for (long a = 0;++a < n; ) {
            //swap e[] items 
            char item = e[a];
            e[a] = e[i[n - 1 - a]];
            e[i[n - 1 - a]] = item;
        }
        delete[]i;
    }
    return e1;
}
string Yti(string e, const long t, const long id) {
    return Yts(e, t ^ id);
}
List* get_splited_from_char_to_array(const string e, long& length, const char sym) {
    List* start = new List();
    List* going = start;

    List* next;
    length = 1;
    for (unsigned long i = 0;i < e.length();i++) {
        //next = &A();
        char it = e.at(i);
        if (it == sym) {
            next = new List();
            going->next = next;
            going = next;
            length++;
            continue;
        }
        going->value << it;

    }
    return going;
}
string Kt(const string e) {
    if (e.empty() || e.length() % 4 == 1)
        return "";
    stringstream answer;
    char n;
    long t, n_int, i = 0;
    for (unsigned long a = 0; a < e.length() && (n = e.at(a++)); )
        if ((n_int = QTIndex(n)) != -1) {
            t = i % 4 ? 64 * t + n_int : n_int;
            i++;
            if (i % 4 != 1)
                answer << (char)(255 & t >> (-2 * i & 6));
        }
    return answer.str();
}
string Gt(string& e, const long user_id_local) {
    if (e.find("audio_api_unavailable") != -1) {
        string i0_kt, i1, n0;
        get_splited(i0_kt, i1, e);
        if (i1 != "") i1 = Kt(i1);
        if (i0_kt = Kt(i0_kt), i1.empty() || i0_kt.empty()) return e;
        long o;
        //delete after using

        List* start = get_splited_from_char_to_array(i1, o, 9);//o = o ? o.split(String.fromCharCode(9)
        while (o--) {//o - start length
            stringstream n0_b, n1_b;
            string ch = start->value.str();
            //splice function
            bool b = false;
            for (unsigned long _ = 0;_ < ch.length();_++) {
                char item = ch.at(_);
                if (item == (char)11) {
                    b = true;
                    continue;
                }
                if (b) n1_b << ch.at(_);
                else n0_b << ch.at(_);
            }
            //end splice function
            switch (n0_b.str().at(0))
            {
            case 'i':i0_kt = Yti(i0_kt, stol(n1_b.str()), user_id_local);break;
            case 's':i0_kt = Yts(i0_kt, stol(n1_b.str()));break;
            case 'v':i0_kt = Ytv(i0_kt);break;
            case 'r':i0_kt = Ytr(i0_kt, stol(n1_b.str()));break;
            default:
                delete_List(start, o);
                return e;
            }
            List* next = start;
            start = start->next;
            delete next;
        }
        if (i0_kt != "" && "http" == i0_kt.substr(0, 4)) {
            return i0_kt;
        }
    }

    return e;
}

void m3u8ToMp3(string& url) {
    long m3u8 = url.find("/index.m3u8");
    if (m3u8 != -1) {
        url = url.replace(m3u8, 11, ".mp3");
        for (int to = -1, i = m3u8;i >= 0;i--) {
            if (url.at(i) == '/') {
                int delta = to - i;

                if (to == -1 || delta < 10)
                    to = i;
                else {
                    url.erase(i + 1, to - i);
                    break;
                }
            }
        }
    }
}
EXPORT char* decode(char* url, const long user_id, const bool need_mp3) {
    string answer;
    try {
        answer = string(url);
        answer = Gt(answer, user_id);
        if (need_mp3)m3u8ToMp3(answer);

        char* z = new char[answer.length() + 1];
        strcpy(z, answer.c_str());
        return z;
    }
    catch (exception e) { return new char[0]; }

}
EXPORT void setUserId(long i) {
    id = i;
}
EXPORT char* toMP3(const char* url) {
    string ans = string(url);
    //char* answ = new char[ans.length()];
    //strcpy( answ,ans.data());
    //return answ;
    m3u8ToMp3(ans);
    char* e = new char[ans.length() + 1];
    strcpy(e, ans.c_str());
    return e;
}

//compile - g++ -shared -fPIC vk-audio-url-decoder.cpp -o lib.so -rdynamic 
