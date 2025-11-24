//FUCNTION TO ADD
Contestants easyContInit(int ID = -1, bool isObjectUsed = 0, string name = "NONE", int age = 0, bool isWoman = 0, double hipCirc = 0, double shoulderCirc = 0, double calfCirc = 0, double neckCirc = 0){
    //EXPLANATION: Adding new contestants is easier. if empty: contestnat id = -1;
    Contestants cont;
    cont.ID = ID;
    cont.isObjectUsed = isObjectUsed;
    cont.name = name;
    cont.age = age;
    cont.isWoman = isWoman;
    cont.hipCirc = hipCirc;
    cont.shoulderCirc = shoulderCirc;
    cont.calfCirc = calfCirc;
    cont.neckCirc = neckCirc;
    return cont;
    
    
    //TODO: Remove endl in deBugInfo and add endl where needed after change
//TODO: Implement new function:easyContInit
//TODO: Remove extra spaces in print contestant 3?4 line
//TODO: Add defalult values in struct Contestants
//TODO: Remoove while trues
//TODO: make the id start form 1 and not 0
/*contestant[0] = easyContInit(0,1,"Mariq",35,1,3.5,5.6,7.8,70);
contestant[1] = easyContInit();
contestant[1].isObjectUsed =  1;*/
}