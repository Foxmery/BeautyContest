#include "debug.h"


void deBugStringArray (string s[],int size){
    
    deBugInfo("SYSTEM: array values: ");
    for(int i = 0; i < size; i++)
        deBugInfo(i << " [" << s[i] << "], ");
    deBugInfo(endl);
}