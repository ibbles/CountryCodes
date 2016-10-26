#include "Common/Common.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include <cstring>



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


struct Country
{
    std::string code;
    CountryId id;

    Country(char const * code, char const * id)
        : code(code)
        , id{id[0], id[1]}
    {
    }
};



class PhoneBook
{
public:
    PhoneBook()
    {
        m_countries.reserve(246);

        // http://country.io/phone.json
        m_countries.emplace_back("880", "BD");
        m_countries.emplace_back("32", "BE");
        m_countries.emplace_back("226", "BF");
        m_countries.emplace_back("359", "BG");
        m_countries.emplace_back("387", "BA");
        m_countries.emplace_back("1246", "BB");
        m_countries.emplace_back("681", "WF");
        m_countries.emplace_back("590", "BL");
        m_countries.emplace_back("1441", "BM");
        m_countries.emplace_back("673", "BN");
        m_countries.emplace_back("591", "BO");
        m_countries.emplace_back("973", "BH");
        m_countries.emplace_back("257", "BI");
        m_countries.emplace_back("229", "BJ");
        m_countries.emplace_back("975", "BT");
        m_countries.emplace_back("1876", "JM");
        m_countries.emplace_back("267", "BW");
        m_countries.emplace_back("685", "WS");
        m_countries.emplace_back("599", "BQ");
        m_countries.emplace_back("55", "BR");
        m_countries.emplace_back("1242", "BS");
        m_countries.emplace_back("441534", "JE");
        m_countries.emplace_back("375", "BY");
        m_countries.emplace_back("501", "BZ");
        m_countries.emplace_back("7", "RU");
        m_countries.emplace_back("250", "RW");
        m_countries.emplace_back("381", "RS");
        m_countries.emplace_back("670", "TL");
        m_countries.emplace_back("262", "RE");
        m_countries.emplace_back("993", "TM");
        m_countries.emplace_back("992", "TJ");
        m_countries.emplace_back("40", "RO");
        m_countries.emplace_back("690", "TK");
        m_countries.emplace_back("245", "GW");
        m_countries.emplace_back("1671", "GU");
        m_countries.emplace_back("502", "GT");
        m_countries.emplace_back("30", "GR");
        m_countries.emplace_back("240", "GQ");
        m_countries.emplace_back("590", "GP");
        m_countries.emplace_back("81", "JP");
        m_countries.emplace_back("592", "GY");
        m_countries.emplace_back("441481", "GG");
        m_countries.emplace_back("594", "GF");
        m_countries.emplace_back("995", "GE");
        m_countries.emplace_back("1473", "GD");
        m_countries.emplace_back("44", "GB");
        m_countries.emplace_back("241", "GA");
        m_countries.emplace_back("503", "SV");
        m_countries.emplace_back("224", "GN");
        m_countries.emplace_back("220", "GM");
        m_countries.emplace_back("299", "GL");
        m_countries.emplace_back("350", "GI");
        m_countries.emplace_back("233", "GH");
        m_countries.emplace_back("968", "OM");
        m_countries.emplace_back("216", "TN");
        m_countries.emplace_back("962", "JO");
        m_countries.emplace_back("385", "HR");
        m_countries.emplace_back("509", "HT");
        m_countries.emplace_back("36", "HU");
        m_countries.emplace_back("852", "HK");
        m_countries.emplace_back("504", "HN");
        m_countries.emplace_back("58", "VE");
        m_countries.emplace_back("1787", "PR");
        m_countries.emplace_back("1939", "PR");
        m_countries.emplace_back("970", "PS");
        m_countries.emplace_back("680", "PW");
        m_countries.emplace_back("351", "PT");
        m_countries.emplace_back("47", "SJ");
        m_countries.emplace_back("595", "PY");
        m_countries.emplace_back("964", "IQ");
        m_countries.emplace_back("507", "PA");
        m_countries.emplace_back("689", "PF");
        m_countries.emplace_back("675", "PG");
        m_countries.emplace_back("51", "PE");
        m_countries.emplace_back("92", "PK");
        m_countries.emplace_back("63", "PH");
        m_countries.emplace_back("870", "PN");
        m_countries.emplace_back("48", "PL");
        m_countries.emplace_back("508", "PM");
        m_countries.emplace_back("260", "ZM");
        m_countries.emplace_back("212", "EH");
        m_countries.emplace_back("372", "EE");
        m_countries.emplace_back("20", "EG");
        m_countries.emplace_back("27", "ZA");
        m_countries.emplace_back("593", "EC");
        m_countries.emplace_back("39", "IT");
        m_countries.emplace_back("84", "VN");
        m_countries.emplace_back("677", "SB");
        m_countries.emplace_back("251", "ET");
        m_countries.emplace_back("252", "SO");
        m_countries.emplace_back("263", "ZW");
        m_countries.emplace_back("966", "SA");
        m_countries.emplace_back("34", "ES");
        m_countries.emplace_back("291", "ER");
        m_countries.emplace_back("382", "ME");
        m_countries.emplace_back("373", "MD");
        m_countries.emplace_back("261", "MG");
        m_countries.emplace_back("590", "MF");
        m_countries.emplace_back("212", "MA");
        m_countries.emplace_back("377", "MC");
        m_countries.emplace_back("998", "UZ");
        m_countries.emplace_back("95", "MM");
        m_countries.emplace_back("223", "ML");
        m_countries.emplace_back("853", "MO");
        m_countries.emplace_back("976", "MN");
        m_countries.emplace_back("692", "MH");
        m_countries.emplace_back("389", "MK");
        m_countries.emplace_back("230", "MU");
        m_countries.emplace_back("356", "MT");
        m_countries.emplace_back("265", "MW");
        m_countries.emplace_back("960", "MV");
        m_countries.emplace_back("596", "MQ");
        m_countries.emplace_back("1670", "MP");
        m_countries.emplace_back("1664", "MS");
        m_countries.emplace_back("222", "MR");
        m_countries.emplace_back("441624", "IM");
        m_countries.emplace_back("256", "UG");
        m_countries.emplace_back("255", "TZ");
        m_countries.emplace_back("60", "MY");
        m_countries.emplace_back("52", "MX");
        m_countries.emplace_back("972", "IL");
        m_countries.emplace_back("33", "FR");
        m_countries.emplace_back("246", "IO");
        m_countries.emplace_back("290", "SH");
        m_countries.emplace_back("358", "FI");
        m_countries.emplace_back("679", "FJ");
        m_countries.emplace_back("500", "FK");
        m_countries.emplace_back("691", "FM");
        m_countries.emplace_back("298", "FO");
        m_countries.emplace_back("505", "NI");
        m_countries.emplace_back("31", "NL");
        m_countries.emplace_back("47", "NO");
        m_countries.emplace_back("264", "NA");
        m_countries.emplace_back("678", "VU");
        m_countries.emplace_back("687", "NC");
        m_countries.emplace_back("227", "NE");
        m_countries.emplace_back("672", "NF");
        m_countries.emplace_back("234", "NG");
        m_countries.emplace_back("64", "NZ");
        m_countries.emplace_back("977", "NP");
        m_countries.emplace_back("674", "NR");
        m_countries.emplace_back("683", "NU");
        m_countries.emplace_back("682", "CK");
        m_countries.emplace_back("225", "CI");
        m_countries.emplace_back("41", "CH");
        m_countries.emplace_back("57", "CO");
        m_countries.emplace_back("86", "CN");
        m_countries.emplace_back("237", "CM");
        m_countries.emplace_back("56", "CL");
        m_countries.emplace_back("61", "CC");
        m_countries.emplace_back("1", "CA");
        m_countries.emplace_back("242", "CG");
        m_countries.emplace_back("236", "CF");
        m_countries.emplace_back("243", "CD");
        m_countries.emplace_back("420", "CZ");
        m_countries.emplace_back("357", "CY");
        m_countries.emplace_back("61", "CX");
        m_countries.emplace_back("506", "CR");
        m_countries.emplace_back("599", "CW");
        m_countries.emplace_back("238", "CV");
        m_countries.emplace_back("53", "CU");
        m_countries.emplace_back("268", "SZ");
        m_countries.emplace_back("963", "SY");
        m_countries.emplace_back("599", "SX");
        m_countries.emplace_back("996", "KG");
        m_countries.emplace_back("254", "KE");
        m_countries.emplace_back("211", "SS");
        m_countries.emplace_back("597", "SR");
        m_countries.emplace_back("686", "KI");
        m_countries.emplace_back("855", "KH");
        m_countries.emplace_back("1869", "KN");
        m_countries.emplace_back("269", "KM");
        m_countries.emplace_back("239", "ST");
        m_countries.emplace_back("421", "SK");
        m_countries.emplace_back("82", "KR");
        m_countries.emplace_back("386", "SI");
        m_countries.emplace_back("850", "KP");
        m_countries.emplace_back("965", "KW");
        m_countries.emplace_back("221", "SN");
        m_countries.emplace_back("378", "SM");
        m_countries.emplace_back("232", "SL");
        m_countries.emplace_back("248", "SC");
        m_countries.emplace_back("7", "KZ");
        m_countries.emplace_back("1345", "KY");
        m_countries.emplace_back("65", "SG");
        m_countries.emplace_back("46", "SE");
        m_countries.emplace_back("249", "SD");
        m_countries.emplace_back("1809", "DO");
        m_countries.emplace_back("1829", "DO");
        m_countries.emplace_back("1767", "DM");
        m_countries.emplace_back("253", "DJ");
        m_countries.emplace_back("45", "DK");
        m_countries.emplace_back("1284", "VG");
        m_countries.emplace_back("49", "DE");
        m_countries.emplace_back("967", "YE");
        m_countries.emplace_back("213", "DZ");
        m_countries.emplace_back("1", "US");
        m_countries.emplace_back("598", "UY");
        m_countries.emplace_back("262", "YT");
        m_countries.emplace_back("1", "UM");
        m_countries.emplace_back("961", "LB");
        m_countries.emplace_back("1758", "LC");
        m_countries.emplace_back("856", "LA");
        m_countries.emplace_back("688", "TV");
        m_countries.emplace_back("886", "TW");
        m_countries.emplace_back("1868", "TT");
        m_countries.emplace_back("90", "TR");
        m_countries.emplace_back("94", "LK");
        m_countries.emplace_back("423", "LI");
        m_countries.emplace_back("371", "LV");
        m_countries.emplace_back("676", "TO");
        m_countries.emplace_back("370", "LT");
        m_countries.emplace_back("352", "LU");
        m_countries.emplace_back("231", "LR");
        m_countries.emplace_back("266", "LS");
        m_countries.emplace_back("66", "TH");
        m_countries.emplace_back("228", "TG");
        m_countries.emplace_back("235", "TD");
        m_countries.emplace_back("1649", "TC");
        m_countries.emplace_back("218", "LY");
        m_countries.emplace_back("379", "VA");
        m_countries.emplace_back("1784", "VC");
        m_countries.emplace_back("971", "AE");
        m_countries.emplace_back("376", "AD");
        m_countries.emplace_back("1268", "AG");
        m_countries.emplace_back("93", "AF");
        m_countries.emplace_back("1264", "AI");
        m_countries.emplace_back("1340", "VI");
        m_countries.emplace_back("354", "IS");
        m_countries.emplace_back("98", "IR");
        m_countries.emplace_back("374", "AM");
        m_countries.emplace_back("355", "AL");
        m_countries.emplace_back("244", "AO");
        m_countries.emplace_back("1684", "AS");
        m_countries.emplace_back("54", "AR");
        m_countries.emplace_back("61", "AU");
        m_countries.emplace_back("43", "AT");
        m_countries.emplace_back("297", "AW");
        m_countries.emplace_back("91", "IN");
        m_countries.emplace_back("35818", "AX");
        m_countries.emplace_back("994", "AZ");
        m_countries.emplace_back("353", "IE");
        m_countries.emplace_back("62", "ID");
        m_countries.emplace_back("380", "UA");
        m_countries.emplace_back("974", "QA");
        m_countries.emplace_back("258", "MZ");

        // If there are multiple matches then the longest one should be returned.
        // We therefore sort the country codes so that the longest ones are tested
        // first.
        std::sort(std::begin(m_countries), std::end(m_countries),
                  [](Country const & lhs, Country const & rhs)
                  {
                      return lhs.code.length() > rhs.code.length();
                  });
    }


    CountryId getCountry(char const * number)
    {
        for (auto & country : m_countries)
        {
            if (startsWith(number, country.code))
            {
                return country.id;
            }
        }

        return not_found;
    }

private:
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
#if 1
        auto mismatchPoint = std::mismatch(std::begin(code), std::end(code), number);
        return mismatchPoint.first == std::end(code);
#elif 0
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
#else
        char const * c = code.c_str();
        while (*c != '\0' && *c == *number)
        {
            ++c;
            ++number;
        }

        return *c == '\0';
#endif
    }

private:
    std::vector<Country> m_countries;
};



int main()
{
    PhoneBook phoneBook;

    std::array<char[9], 1000> numbers;
    common::Random random;

    for (int i = 0; i < 1; ++i)
    {
        common::genrateNumbers(numbers, random);
        for (auto const & number : numbers)
        {
            CountryId country = phoneBook.getCountry(number);
            if (country.id[0] != 0)
            {
                std::cout << "Number '" << number << "' has country " << country.id << '\n';
            }
            else
            {
                std::cout << "No match for number '" << number << "'\n";
            }
        }
    }
}
