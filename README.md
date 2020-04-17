# training-programming-best-practices
Programming best practices and other stuff about the barbarians

| | |
|:---|:---|
| **Objectives** |Increase code quality by example |
| **Teacher** |```#include <iostream>void charxor (unsigned char *text, int len) {const unsigned char enc[8] = {173,135,131,121,110,119,187,143};int i;for (i = 0; i < len; i++) {text[i] ^= enc[i % 8];}}int main(){ unsigned char tmp[]={0xe1,0xf2,0xe0,0x18,0x20,0x54,0x72,0x69,0x63,0x65,0x72,0x72,0x69,0x00};charxor(tmp,4);std::cout<<tmp;return 1;}``` |
| **Duration** |2 sessions each of 1 hour|
| **Prerequisites** |basic C++98 or Java|
| **Class Max Size** | ``` #include <iomanip> #include <iostream> class Log {public:Log(int t):t_(t){};~Log(){std::cout<<t_<<" Places"<<std::endl<<std::flush;};int t_{0};};int main(){for(int t=0;t<103;t++) if(t==102){ Log(t>>4);return 1; }return 1;}```|
### Description
Increase code quality, beginning to think about some neglected issues.
My personal experiences and interpretation.
### Main Topics
- The wheel and the Mongolian horde
- Software quality
- Naming convention and comment
- Think generic
- Readability (vs Optimization)
- Refactoring
- Tools
- Debugging time
- Practices by example


### Material
You can find some slides and *.h or *.cpp files in the doc folder, daily update.

### Time and place 
To be decided

