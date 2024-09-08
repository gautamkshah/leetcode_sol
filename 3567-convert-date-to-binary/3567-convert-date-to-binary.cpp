class Solution {
public:
    string convertDateToBinary(string date) {
    // Split the input date into year, month, and day
    int year, month, day;
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);

    // Convert each component to binary without leading zeros
    string yearBinary = bitset<32>(year).to_string();
    yearBinary.erase(0, yearBinary.find_first_not_of('0')); // Remove leading zeros
    
    string monthBinary = bitset<8>(month).to_string();
    monthBinary.erase(0, monthBinary.find_first_not_of('0')); // Remove leading zeros
    
    string dayBinary = bitset<8>(day).to_string();
    dayBinary.erase(0, dayBinary.find_first_not_of('0')); // Remove leading zeros
    
    // Combine the binary representations in the required format
    return yearBinary + "-" + monthBinary + "-" + dayBinary;
}
};