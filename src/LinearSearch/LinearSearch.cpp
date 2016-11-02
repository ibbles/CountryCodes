#include "Common/Common.hpp"

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>

#include <cstring>
#include <chrono>
#include <iomanip>


#define USE_STD_STRING 1
#define USE_PACKED_STRINGS 2
#define STRING_FORMAT USE_STD_STRING


#if STRING_FORMAT == USE_STD_STRING
    #define USE_MISMATCH 1
    #define USE_FOR_EACH 2
    #define USE_C_STYLE 3
    #define MATCH_ALGORITHM USE_C_STYLE
#elif STRING_FORMAT == USE_PACKED_STRINGS
    #define USE_STEP 1
#else
    #error
#endif



struct CountryId
{
    char id[2];

    constexpr CountryId(char c0, char c1)
        : id {c0, c1}
    {
    }
};



std::ostream& operator<<(std::ostream & out, CountryId const & id)
{
    out << id.id[0] << id.id[1];
    return out;
}


static constexpr CountryId not_found {'\0', '\0'};



struct StringCountry
{
    std::string code;
    CountryId id;

    StringCountry(char const * code, char const * id)
        : code(code)
        , id{id[0], id[1]}
    {
    }
};




struct PackedCountry
{
    char const * code;
    CountryId id;

    PackedCountry(char const * code, CountryId id)
        : code(code)
        , id{id}
    {
    }
};


void fillCountries(std::vector<StringCountry> & countries)
{
    countries.reserve(246);

    // http://country.io/phone.json
    countries.emplace_back("880", "BD");
    countries.emplace_back("32", "BE");
    countries.emplace_back("226", "BF");
    countries.emplace_back("359", "BG");
    countries.emplace_back("387", "BA");
    countries.emplace_back("1246", "BB");
    countries.emplace_back("681", "WF");
    countries.emplace_back("590", "BL");
    countries.emplace_back("1441", "BM");
    countries.emplace_back("673", "BN");
    countries.emplace_back("591", "BO");
    countries.emplace_back("973", "BH");
    countries.emplace_back("257", "BI");
    countries.emplace_back("229", "BJ");
    countries.emplace_back("975", "BT");
    countries.emplace_back("1876", "JM");
    countries.emplace_back("267", "BW");
    countries.emplace_back("685", "WS");
    countries.emplace_back("599", "BQ");
    countries.emplace_back("55", "BR");
    countries.emplace_back("1242", "BS");
    countries.emplace_back("441534", "JE");
    countries.emplace_back("375", "BY");
    countries.emplace_back("501", "BZ");
    countries.emplace_back("7", "RU");
    countries.emplace_back("250", "RW");
    countries.emplace_back("381", "RS");
    countries.emplace_back("670", "TL");
    countries.emplace_back("262", "RE");
    countries.emplace_back("993", "TM");
    countries.emplace_back("992", "TJ");
    countries.emplace_back("40", "RO");
    countries.emplace_back("690", "TK");
    countries.emplace_back("245", "GW");
    countries.emplace_back("1671", "GU");
    countries.emplace_back("502", "GT");
    countries.emplace_back("30", "GR");
    countries.emplace_back("240", "GQ");
    countries.emplace_back("590", "GP");
    countries.emplace_back("81", "JP");
    countries.emplace_back("592", "GY");
    countries.emplace_back("441481", "GG");
    countries.emplace_back("594", "GF");
    countries.emplace_back("995", "GE");
    countries.emplace_back("1473", "GD");
    countries.emplace_back("44", "GB");
    countries.emplace_back("241", "GA");
    countries.emplace_back("503", "SV");
    countries.emplace_back("224", "GN");
    countries.emplace_back("220", "GM");
    countries.emplace_back("299", "GL");
    countries.emplace_back("350", "GI");
    countries.emplace_back("233", "GH");
    countries.emplace_back("968", "OM");
    countries.emplace_back("216", "TN");
    countries.emplace_back("962", "JO");
    countries.emplace_back("385", "HR");
    countries.emplace_back("509", "HT");
    countries.emplace_back("36", "HU");
    countries.emplace_back("852", "HK");
    countries.emplace_back("504", "HN");
    countries.emplace_back("58", "VE");
    countries.emplace_back("1787", "PR");
    countries.emplace_back("1939", "PR");
    countries.emplace_back("970", "PS");
    countries.emplace_back("680", "PW");
    countries.emplace_back("351", "PT");
    countries.emplace_back("47", "SJ");
    countries.emplace_back("595", "PY");
    countries.emplace_back("964", "IQ");
    countries.emplace_back("507", "PA");
    countries.emplace_back("689", "PF");
    countries.emplace_back("675", "PG");
    countries.emplace_back("51", "PE");
    countries.emplace_back("92", "PK");
    countries.emplace_back("63", "PH");
    countries.emplace_back("870", "PN");
    countries.emplace_back("48", "PL");
    countries.emplace_back("508", "PM");
    countries.emplace_back("260", "ZM");
    countries.emplace_back("212", "EH");
    countries.emplace_back("372", "EE");
    countries.emplace_back("20", "EG");
    countries.emplace_back("27", "ZA");
    countries.emplace_back("593", "EC");
    countries.emplace_back("39", "IT");
    countries.emplace_back("84", "VN");
    countries.emplace_back("677", "SB");
    countries.emplace_back("251", "ET");
    countries.emplace_back("252", "SO");
    countries.emplace_back("263", "ZW");
    countries.emplace_back("966", "SA");
    countries.emplace_back("34", "ES");
    countries.emplace_back("291", "ER");
    countries.emplace_back("382", "ME");
    countries.emplace_back("373", "MD");
    countries.emplace_back("261", "MG");
    countries.emplace_back("590", "MF");
    countries.emplace_back("212", "MA");
    countries.emplace_back("377", "MC");
    countries.emplace_back("998", "UZ");
    countries.emplace_back("95", "MM");
    countries.emplace_back("223", "ML");
    countries.emplace_back("853", "MO");
    countries.emplace_back("976", "MN");
    countries.emplace_back("692", "MH");
    countries.emplace_back("389", "MK");
    countries.emplace_back("230", "MU");
    countries.emplace_back("356", "MT");
    countries.emplace_back("265", "MW");
    countries.emplace_back("960", "MV");
    countries.emplace_back("596", "MQ");
    countries.emplace_back("1670", "MP");
    countries.emplace_back("1664", "MS");
    countries.emplace_back("222", "MR");
    countries.emplace_back("441624", "IM");
    countries.emplace_back("256", "UG");
    countries.emplace_back("255", "TZ");
    countries.emplace_back("60", "MY");
    countries.emplace_back("52", "MX");
    countries.emplace_back("972", "IL");
    countries.emplace_back("33", "FR");
    countries.emplace_back("246", "IO");
    countries.emplace_back("290", "SH");
    countries.emplace_back("358", "FI");
    countries.emplace_back("679", "FJ");
    countries.emplace_back("500", "FK");
    countries.emplace_back("691", "FM");
    countries.emplace_back("298", "FO");
    countries.emplace_back("505", "NI");
    countries.emplace_back("31", "NL");
    countries.emplace_back("47", "NO");
    countries.emplace_back("264", "NA");
    countries.emplace_back("678", "VU");
    countries.emplace_back("687", "NC");
    countries.emplace_back("227", "NE");
    countries.emplace_back("672", "NF");
    countries.emplace_back("234", "NG");
    countries.emplace_back("64", "NZ");
    countries.emplace_back("977", "NP");
    countries.emplace_back("674", "NR");
    countries.emplace_back("683", "NU");
    countries.emplace_back("682", "CK");
    countries.emplace_back("225", "CI");
    countries.emplace_back("41", "CH");
    countries.emplace_back("57", "CO");
    countries.emplace_back("86", "CN");
    countries.emplace_back("237", "CM");
    countries.emplace_back("56", "CL");
    countries.emplace_back("61", "CC");
    countries.emplace_back("1", "CA");
    countries.emplace_back("242", "CG");
    countries.emplace_back("236", "CF");
    countries.emplace_back("243", "CD");
    countries.emplace_back("420", "CZ");
    countries.emplace_back("357", "CY");
    countries.emplace_back("61", "CX");
    countries.emplace_back("506", "CR");
    countries.emplace_back("599", "CW");
    countries.emplace_back("238", "CV");
    countries.emplace_back("53", "CU");
    countries.emplace_back("268", "SZ");
    countries.emplace_back("963", "SY");
    countries.emplace_back("599", "SX");
    countries.emplace_back("996", "KG");
    countries.emplace_back("254", "KE");
    countries.emplace_back("211", "SS");
    countries.emplace_back("597", "SR");
    countries.emplace_back("686", "KI");
    countries.emplace_back("855", "KH");
    countries.emplace_back("1869", "KN");
    countries.emplace_back("269", "KM");
    countries.emplace_back("239", "ST");
    countries.emplace_back("421", "SK");
    countries.emplace_back("82", "KR");
    countries.emplace_back("386", "SI");
    countries.emplace_back("850", "KP");
    countries.emplace_back("965", "KW");
    countries.emplace_back("221", "SN");
    countries.emplace_back("378", "SM");
    countries.emplace_back("232", "SL");
    countries.emplace_back("248", "SC");
    countries.emplace_back("7", "KZ");
    countries.emplace_back("1345", "KY");
    countries.emplace_back("65", "SG");
    countries.emplace_back("46", "SE");
    countries.emplace_back("249", "SD");
    countries.emplace_back("1809", "DO");
    countries.emplace_back("1829", "DO");
    countries.emplace_back("1767", "DM");
    countries.emplace_back("253", "DJ");
    countries.emplace_back("45", "DK");
    countries.emplace_back("1284", "VG");
    countries.emplace_back("49", "DE");
    countries.emplace_back("967", "YE");
    countries.emplace_back("213", "DZ");
    countries.emplace_back("1", "US");
    countries.emplace_back("598", "UY");
    countries.emplace_back("262", "YT");
    countries.emplace_back("1", "UM");
    countries.emplace_back("961", "LB");
    countries.emplace_back("1758", "LC");
    countries.emplace_back("856", "LA");
    countries.emplace_back("688", "TV");
    countries.emplace_back("886", "TW");
    countries.emplace_back("1868", "TT");
    countries.emplace_back("90", "TR");
    countries.emplace_back("94", "LK");
    countries.emplace_back("423", "LI");
    countries.emplace_back("371", "LV");
    countries.emplace_back("676", "TO");
    countries.emplace_back("370", "LT");
    countries.emplace_back("352", "LU");
    countries.emplace_back("231", "LR");
    countries.emplace_back("266", "LS");
    countries.emplace_back("66", "TH");
    countries.emplace_back("228", "TG");
    countries.emplace_back("235", "TD");
    countries.emplace_back("1649", "TC");
    countries.emplace_back("218", "LY");
    countries.emplace_back("379", "VA");
    countries.emplace_back("1784", "VC");
    countries.emplace_back("971", "AE");
    countries.emplace_back("376", "AD");
    countries.emplace_back("1268", "AG");
    countries.emplace_back("93", "AF");
    countries.emplace_back("1264", "AI");
    countries.emplace_back("1340", "VI");
    countries.emplace_back("354", "IS");
    countries.emplace_back("98", "IR");
    countries.emplace_back("374", "AM");
    countries.emplace_back("355", "AL");
    countries.emplace_back("244", "AO");
    countries.emplace_back("1684", "AS");
    countries.emplace_back("54", "AR");
    countries.emplace_back("61", "AU");
    countries.emplace_back("43", "AT");
    countries.emplace_back("297", "AW");
    countries.emplace_back("91", "IN");
    countries.emplace_back("35818", "AX");
    countries.emplace_back("994", "AZ");
    countries.emplace_back("353", "IE");
    countries.emplace_back("62", "ID");
    countries.emplace_back("380", "UA");
    countries.emplace_back("974", "QA");
    countries.emplace_back("258", "MZ");

    // If there are multiple matches then the longest one should be returned.
    // We therefore sort the country codes so that the longest ones are tested
    // first.
    std::sort(std::begin(countries),
              std::end(countries),
              [](StringCountry const & lhs, StringCountry const & rhs)
              {
                  return lhs.code.length() > rhs.code.length();
              });

}



class PhoneBook
{
public:
    PhoneBook()
    {
#if STRING_FORMAT == USE_STD_STRING
        fillCountries(m_countries);
#elif STRING_FORMAT == USE_PACKED_STRINGS
        std::vector<StringCountry> countries;
        fillCountries(countries);
#else
    #error
#endif


#if STRING_FORMAT == USE_PACKED_STRINGS
        // Pre-allocate memory for packed code digits.
        size_t numCodeDigits = 0;
        for (auto const & country : countries)
        {
            numCodeDigits += country.code.length() + 1; // +1 for '\0'.
        }
        m_codeData.reserve(numCodeDigits);

        for (auto const & country : countries)
        {
            m_countries.emplace_back(&m_codeData[m_codeData.size()], country.id);
            std::copy(std::begin(country.code), std::end(country.code), std::back_inserter(m_codeData));
            m_codeData.push_back('\0');
        }
#endif
    }


    CountryId getCountry(char const * number)
    {
#if STRING_FORMAT == USE_STD_STRING
        for (auto & country : m_countries)
        {
            if (startsWith(number, country.code))
            {
                return country.id;
            }
        }

        return not_found;
#elif STRING_FORMAT == USE_PACKED_STRINGS
        size_t countryIndex = 0;
        auto begin = &m_codeData[0];
        auto end = &m_codeData[m_codeData.size()];
        auto c = begin;
        while (c != end)
        {
            auto n = number;
            while (*c != '\0' && *c == *n)
            {
                ++c;
                ++n;
            }
            if (*c == '\0')
            {
                return m_countries[countryIndex].id;
            }

            ++countryIndex;
            while(*c != '\0')
            {
                ++c;
            }
            ++c;
        }

        return not_found;
#else
    #error
#endif
    }

private:
#if STRING_FORMAT == USE_STD_STRING
    /**
     * Returns true if the given number starts with the given country code.
     *
     * The number must contain at last as many digits as the country code.
     *
     * @param number The phone number to search in.
     * @param code The country code to search for.
     * @return True if the number starts with the country code.
     */
    bool startsWith(char const * number, std::string const & code)
    {
#if MATCH_ALGORITHM == USE_MISMATCH
        auto mismatchPoint = std::mismatch(std::begin(code), std::end(code), number);
        return mismatchPoint.first == std::end(code);
#elif MATCH_ALGORITHM == USE_FOR_EACH
        // Does not check for termination of the 'number' string. Assumes that
        // the country code is shorter than the phone number.
        for (auto c : code)
        {
            if (c != *number)
            {
                return false;
            }

            ++number;
        }

        return true;
#elif MATCH_ALGORITHM == USE_C_STYLE
        char const * c = code.c_str();
        while (*c != '\0' && *c == *number)
        {
            ++c;
            ++number;
        }

        return *c == '\0';
#else
    #error
#endif
    }
#endif

private:
#if STRING_FORMAT == USE_STD_STRING
    std::vector<StringCountry> m_countries;
#elif STRING_FORMAT == USE_PACKED_STRINGS
    std::vector<PackedCountry> m_countries;
    std::vector<char> m_codeData;
#else
    #error
#endif
};



int main()
{
#if 0
    std::cout << "Configuration:\n";
    std::cout << "  STRING_FORMAT: " << STRING_FORMAT << "\n";
#if STRING_FORMAT == USE_STD_STRING
    std::cout << "  MATCH_ALGORITHM: " << MATCH_ALGORITHM << "\n";
#endif
    std::cout << "\n";
#endif

    PhoneBook phoneBook;

    constexpr int numbersPerIteration = 1000;
    constexpr int numIterations = 100;
    constexpr int numNumbers = numbersPerIteration * numIterations;

    std::array<char[9], numbersPerIteration> numbers;
    common::Random random;

    int numMatches = 0;

    auto timeStart = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numIterations; ++i)
    {
        common::genrateNumbers(numbers, random);
        for (auto const & number : numbers)
        {
            CountryId country = phoneBook.getCountry(number);
            if (country.id[0] != 0)
            {
                ++numMatches;
                //std::cout << "Number '" << number << "' has country " << country << '\n';
            }
            else
            {
                //std::cout << "No match for number '" << number << "'\n";
            }
        }
    }
    auto timeEnd = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(timeEnd - timeStart);

    std::cout << "Found " << numMatches << " matches. "
              << "Took " << std::setprecision(7) << std::fixed << duration.count() << " s. " << std::defaultfloat
              << std::setw(14) << duration.count() / numNumbers << " s / number.\n";
}
