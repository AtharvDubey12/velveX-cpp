#include "../headers/integHandler.h"
#include "../headers/tokenProcessor.h"
#include "../headers/fracHandler.h"
#include "../headers/sqrtHandler.h"
#include "../headers/parser.h"
#include "../headers/globalVars.h"
#include <unordered_map>



using namespace std; 



string tokenProcessor(vector<string>& tokenList){
    string output = "";
    string keyword = tokenList[0];
  //  for (auto& it : tokenList) trim(it);
  //  for (auto& it : tokenList) cout << it << ',' << endl;
   // cout << "ended once" << endl;

    if(keyword == "Integ") return integHandler(tokenList);
    else if(keyword == "Frac") return fracHandler(tokenList);
    else if(keyword == "Diff") return diffHandler(tokenList);
    else if(keyword == "Pdiff") return pdiffHandler(tokenList);
    else if(keyword == "Sqrt") return sqrtHandler(tokenList);
    else if(keyword == "Lim") return limitHandler(tokenList);
    else if(keyword == "Sum") return sumHandler(tokenList);
    else if(keyword == "C") return combinationHandler(tokenList,0);
    else if(keyword == "P") return combinationHandler(tokenList,1);
    else if(keyword == "Vec") return vectorHandler(tokenList);
    else if(keyword == "Line") return overlineHandler(tokenList);
    else if(keyword == "Mx") return matrixHandler(tokenList, 0);
    else if(keyword == "Dt") return matrixHandler(tokenList, 1);
    else if(keyword == "Bold") return boldmathHandler(tokenList);
    else if(keyword == "Piece") return piecewiseHandler(tokenList);
    else if(keyword == "Set") return setNotateHandler(tokenList);
    else if(keyword == "Prod") return prodHandler(tokenList);
    else if(keyword == "Txt") return textHandler(tokenList);
    else if(keyword == "_") return scriptHandler(tokenList,1);
    else if(keyword == "^") return scriptHandler(tokenList,0);
    else if(keyword == "Taylor") return taylorHandler(tokenList);
    else if(keyword == "Maclaurin") return maclaurinHandler(tokenList);
    else if(keyword == "Fourier") return fourierHandler(tokenList);
    else if(keyword == "Dirichlet") return dirichletHandler(tokenList);
    else if(keyword == "Binomial") return binomHandler(tokenList);
    else if(keyword == "Legendre") return legendreHandler(tokenList);
    else if(keyword == "Laurent") return laurentHandler(tokenList);
    else if(keyword == "<=") return " \\leq ";
    else if(keyword == ">=") return " \\geq ";
    else if(keyword == "!=") return " \\neq ";
    else if(keyword == "All") return " \\forall ";
    else if(keyword == "Del") return " \\delta ";
    else if(keyword == "Delta") return " \\Delta ";
    else if(keyword == "Nabla") return " \\nabla ";
    else if(keyword == "Om") return " \\omega ";
    else if(keyword == "Omega") return " \\Omega ";
    else if(keyword == "Zeta") return " \\zeta ";
    else if(keyword == "Inf") return " \\infty ";
    else if(keyword == "__") return " \\,\\,\\, ";
    else if(keyword == "Theta") return " \\theta ";
    else if(keyword == "Vtheta") return " \\vartheta ";
    else if(keyword == "Epsilon") return " \\epsilon ";
    else if(keyword == "Vepsilon") return " \\varepsilon ";
    else if(keyword == "Alpha") return " \\alpha ";
    else if(keyword == "Beta") return " \\beta ";
    else if(keyword == "Gam") return " \\gamma ";
    else if(keyword == "Gamma") return " \\Gamma ";
    else if(keyword == "Lambda") return " \\lambda ";
    else if(keyword == "Nu") return " \\nu ";
    else if(keyword == "Pi") return " \\pi ";
    else if(keyword == "~~") return " \\approx ";
    else if(keyword == "==") return " \\equiv ";
    else if(keyword == "~=") return " \\cong ";
    else if(keyword == "!~=") return " \\ncong ";
    else if(keyword == "Angle") return " \\angle ";
    else if(keyword == "~>") return " \\rightarrow ";
    else if(keyword == "<~") return " \\leftarrow ";
    else if(keyword == "<~>") return " \\leftrightarrow ";
    else if(keyword == "=>") return " \\Rightarrow ";
    else if(keyword == "<=>") return " \\Leftrightarrow ";
    else if(keyword == "In") return " \\in ";
    else if(keyword == "!In") return " \\notin ";
    else if(keyword == "Sub") return " \\subset ";
    else if(keyword == "Sub=") return " \\subseteq ";
    else if(keyword == "!Sub") return " \\nsubseteq ";
    else if(keyword == "Re") return " \\Re ";
    else if (keyword == "\\n") return " \\\\ \n";
    else if (keyword == "Ignore") return "";
     else if (keyword == "Let") {
        custom_defines[tokenList[1]] = expressionParser(tokenList[2]);
        return "";
    }
    else if (custom_defines.find(keyword) != custom_defines.end()) return custom_defines[keyword];
    else return " " + tokenList[0];

    return "";
}