#include<iostream>
#include<vector>
#include<string>
#include<regex>
#include<sstream>
#include<cmath>

#define ll long long int
using namespace std;


ll regA = 35200350, regB = 0, regC = 0;

ll literal2combo(ll operand)
{
    switch (operand)
    {
        case 0: return 0; break;
        case 1: return 1; break;
        case 2: return 2; break;
        case 3: return 3; break;
        case 4: return regA; break;
        case 5: return regB; break;
        case 6: return regC; break;
    }
}

void adv(ll operand)
{
    // adv takes in combo operand, so we convert it appropriately
    operand = literal2combo(operand);
    ll nume = regA;
    ll deno = pow(2, operand);
    regA = nume/deno;
}

void bxl(ll operand)
{
    // given operand is a literal operand
    regB = (regB)^(operand);
}

void bst(ll operand)
{
    operand = literal2combo(operand);
    regB = operand % 8;
}

void jnz(ll operand, int& index)
{
    if(regA != 0)
    {
        index = operand -2;
    }
}

void bxc()
{
    regB = regB^regC;
}

void out(ll operand, string& outputString)
{
    operand = literal2combo(operand);
    outputString += to_string(operand%8);
    outputString += ",";
}

void bdv(ll operand)
{
    operand = literal2combo(operand);
    ll nume = regA;
    ll deno = pow(2, operand);
    regB = nume/deno;
}

void cdv(ll operand)
{
    operand = literal2combo(operand);
    ll nume = regA;
    ll deno = pow(2, operand);
    regC = nume/deno;
}

void operationfxn(int opcode, ll& operand, int& index, string& outputString)
{
    switch (opcode)
    {
        case 0: 
            adv(operand); 
            break;
        case 1: 
            bxl(operand); 
            break;
        case 2: 
            bst(operand); 
            break;
        case 3: 
            jnz(operand, index); 
            break;
        case 4:    
            bxc(); 
            break;
        case 5:     
            out(operand, outputString); 
            break;
        case 6: 
            bdv(operand); 
            break;
        case 7: 
            cdv(operand); 
            break;
    }
}


int main()
{
    // Step 1: Let's get the input and store it appropriately
    int i = 0;
    for(i = 0; i<3; i++)
    {
        string line;
        getline(cin, line);
        smatch match;
        if(regex_search(line, match, regex(R"(Register ([A-C]): (\d+))")))
        {
            char regName = match[1].str()[0];
            ll value = stoi(match[2].str());
            switch (regName)
            {
                case 'A': 
                    regA = value;
                    break;
                case 'B':
                    regB = value;
                    break;
                case 'C':
                    regC = value;
                    break;
            }
        }
    }
    vector<ll> program;
    string programStr;
    getline(cin, programStr);

    size_t colonPos = programStr.find(": ");
    string numbersStr;
    numbersStr = programStr.substr(colonPos+2);
    stringstream ss(numbersStr);
    string token;
    while(getline(ss, token, ','))
    {
        program.push_back(stoi(token));
    }

    // Let's create appropriate functions for the instructions
    int index =0;
    string outputString = "";
    while(index<program.size())
    {
        int opcode = program[index];
        ll operand = program[index+1];
        operationfxn(opcode, operand, index, outputString);
        index+=2;
    }

    if(!outputString.empty()) outputString.erase(outputString.length() - 1);
    cout<<"Output string: "<<outputString<<endl;
    
}
    


    