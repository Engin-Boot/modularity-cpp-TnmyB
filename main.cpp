#include "TelCoColorCoder.h"
#include "ColorTest.h"

namespace TelCoColorCoder {
    ColorPair GetColorFromPairNumber(int pairNumber) {
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor =
            (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor =
            (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }
    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
    }
}

std::string ToString() {
   
    int colorno=1;
    std::string list;

        for (; colorno <= 25; colorno++) {
            list += std::to_string(colorno);
            list += " ";
            TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorFromPairNumber(colorno);
            list += colorPair.ToString();
            list += "\n";
        }
       return list;
}

int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);
  
    return 0;
}
