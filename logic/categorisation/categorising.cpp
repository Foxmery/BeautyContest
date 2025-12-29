#include "categorising.h"



// - Categories: I. 14-16  II. 17-19  III. 20-22 IV. 23-25 (in different arrays)
// - Output all the categories (if no contestants output a message for that)
void categorizeContestantsByAge(Contestants contestant[], Contestants category14_16[], Contestants category17_19[], Contestants category20_22[], Contestants category23_25[]){
    for(int i = getNextUsedSlot(contestant, 0); i != -1; i = getNextUsedSlot(contestant, i + 1)){
        deBugInfo("SYSTEM: i: " << i << endl);

        Contestants cont = contestant[i];
        int contAge = cont.age;

        int validIndexToPut;
        //LATER: make this with Contestants temp; use dupe function to make logic more readble
        if (contAge >= 14 && contAge <= 16){
            validIndexToPut = getNextFreeSlot(category14_16);
            category14_16[validIndexToPut] = cont;
            deBugInfo("SYSTEM: Put cont " << cont.name << " at category14_16" << endl);
            
        } else if(contAge >= 17 && contAge <= 19){
            validIndexToPut = getNextFreeSlot(category17_19);
            category17_19[validIndexToPut] = cont;
            deBugInfo("SYSTEM: Put cont " << cont.name << " at category17_19" << endl);

        } else if(contAge >= 20 && contAge <= 22){
            validIndexToPut = getNextFreeSlot(category20_22);
            category20_22[validIndexToPut] = cont;
            deBugInfo("SYSTEM: Put cont " << cont.name << " at category20_22" << endl);

        } else if(contAge >= 23 && contAge <= 25){
            validIndexToPut = getNextFreeSlot(category23_25);
            category23_25[validIndexToPut] = cont;
            deBugInfo("SYSTEM: Put cont " << cont.name << " at category23_25" << endl);

        } else {
            deBugInfo("WARNING - categorizeContestantsByAge: Contestant is too old. Skipping. Age: " << contAge << endl);
        }        
    }
    
    clearConsole();
    printAllContestantsFormatted(category14_16, "Category 14/16 years");
    
    printAllContestantsFormatted(category17_19, "Category 17/19 years");

    printAllContestantsFormatted(category20_22, "Category 20/22 years");

    printAllContestantsFormatted(category23_25, "Category 23/25 years");

}

