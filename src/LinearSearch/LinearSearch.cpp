#include "Common/Common.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>

struct CountryId
{
    char id[2];
};

class PhoneBook
{
private:
    using Country = std::pair<std::string, std::string>;

public:
    PhoneBook()
    {
        std::vector<Country> countries;
        countries.reserve(246);
        m_codeOffsets.reserve(246);
        m_countries.reserve(246);

        // http://country.io/phone.json
        countries.push_back(std::make_pair("880", "BD"));
        countries.push_back(std::make_pair("32", "BE"));
        countries.push_back(std::make_pair("226", "BF"));
        countries.push_back(std::make_pair("359", "BG"));
        countries.push_back(std::make_pair("387", "BA"));
        countries.push_back(std::make_pair("1246", "BB"));
        countries.push_back(std::make_pair("681", "WF"));
        countries.push_back(std::make_pair("590", "BL"));
        countries.push_back(std::make_pair("1441", "BM"));
        countries.push_back(std::make_pair("673", "BN"));
        countries.push_back(std::make_pair("591", "BO"));
        countries.push_back(std::make_pair("973", "BH"));
        countries.push_back(std::make_pair("257", "BI"));
        countries.push_back(std::make_pair("229", "BJ"));
        countries.push_back(std::make_pair("975", "BT"));
        countries.push_back(std::make_pair("1876", "JM"));
        countries.push_back(std::make_pair("267", "BW"));
        countries.push_back(std::make_pair("685", "WS"));
        countries.push_back(std::make_pair("599", "BQ"));
        countries.push_back(std::make_pair("55", "BR"));
        countries.push_back(std::make_pair("1242", "BS"));
        countries.push_back(std::make_pair("441534", "JE"));
        countries.push_back(std::make_pair("375", "BY"));
        countries.push_back(std::make_pair("501", "BZ"));
        countries.push_back(std::make_pair("7", "RU"));
        countries.push_back(std::make_pair("250", "RW"));
        countries.push_back(std::make_pair("381", "RS"));
        countries.push_back(std::make_pair("670", "TL"));
        countries.push_back(std::make_pair("262", "RE"));
        countries.push_back(std::make_pair("993", "TM"));
        countries.push_back(std::make_pair("992", "TJ"));
        countries.push_back(std::make_pair("40", "RO"));
        countries.push_back(std::make_pair("690", "TK"));
        countries.push_back(std::make_pair("245", "GW"));
        countries.push_back(std::make_pair("1671", "GU"));
        countries.push_back(std::make_pair("502", "GT"));
        countries.push_back(std::make_pair("30", "GR"));
        countries.push_back(std::make_pair("240", "GQ"));
        countries.push_back(std::make_pair("590", "GP"));
        countries.push_back(std::make_pair("81", "JP"));
        countries.push_back(std::make_pair("592", "GY"));
        countries.push_back(std::make_pair("441481", "GG"));
        countries.push_back(std::make_pair("594", "GF"));
        countries.push_back(std::make_pair("995", "GE"));
        countries.push_back(std::make_pair("1473", "GD"));
        countries.push_back(std::make_pair("44", "GB"));
        countries.push_back(std::make_pair("241", "GA"));
        countries.push_back(std::make_pair("503", "SV"));
        countries.push_back(std::make_pair("224", "GN"));
        countries.push_back(std::make_pair("220", "GM"));
        countries.push_back(std::make_pair("299", "GL"));
        countries.push_back(std::make_pair("350", "GI"));
        countries.push_back(std::make_pair("233", "GH"));
        countries.push_back(std::make_pair("968", "OM"));
        countries.push_back(std::make_pair("216", "TN"));
        countries.push_back(std::make_pair("962", "JO"));
        countries.push_back(std::make_pair("385", "HR"));
        countries.push_back(std::make_pair("509", "HT"));
        countries.push_back(std::make_pair("36", "HU"));
        countries.push_back(std::make_pair("852", "HK"));
        countries.push_back(std::make_pair("504", "HN"));
        countries.push_back(std::make_pair("58", "VE"));
        countries.push_back(std::make_pair("1787", "PR"));
        countries.push_back(std::make_pair("1939", "PR"));
        countries.push_back(std::make_pair("970", "PS"));
        countries.push_back(std::make_pair("680", "PW"));
        countries.push_back(std::make_pair("351", "PT"));
        countries.push_back(std::make_pair("47", "SJ"));
        countries.push_back(std::make_pair("595", "PY"));
        countries.push_back(std::make_pair("964", "IQ"));
        countries.push_back(std::make_pair("507", "PA"));
        countries.push_back(std::make_pair("689", "PF"));
        countries.push_back(std::make_pair("675", "PG"));
        countries.push_back(std::make_pair("51", "PE"));
        countries.push_back(std::make_pair("92", "PK"));
        countries.push_back(std::make_pair("63", "PH"));
        countries.push_back(std::make_pair("870", "PN"));
        countries.push_back(std::make_pair("48", "PL"));
        countries.push_back(std::make_pair("508", "PM"));
        countries.push_back(std::make_pair("260", "ZM"));
        countries.push_back(std::make_pair("212", "EH"));
        countries.push_back(std::make_pair("372", "EE"));
        countries.push_back(std::make_pair("20", "EG"));
        countries.push_back(std::make_pair("27", "ZA"));
        countries.push_back(std::make_pair("593", "EC"));
        countries.push_back(std::make_pair("39", "IT"));
        countries.push_back(std::make_pair("84", "VN"));
        countries.push_back(std::make_pair("677", "SB"));
        countries.push_back(std::make_pair("251", "ET"));
        countries.push_back(std::make_pair("252", "SO"));
        countries.push_back(std::make_pair("263", "ZW"));
        countries.push_back(std::make_pair("966", "SA"));
        countries.push_back(std::make_pair("34", "ES"));
        countries.push_back(std::make_pair("291", "ER"));
        countries.push_back(std::make_pair("382", "ME"));
        countries.push_back(std::make_pair("373", "MD"));
        countries.push_back(std::make_pair("261", "MG"));
        countries.push_back(std::make_pair("590", "MF"));
        countries.push_back(std::make_pair("212", "MA"));
        countries.push_back(std::make_pair("377", "MC"));
        countries.push_back(std::make_pair("998", "UZ"));
        countries.push_back(std::make_pair("95", "MM"));
        countries.push_back(std::make_pair("223", "ML"));
        countries.push_back(std::make_pair("853", "MO"));
        countries.push_back(std::make_pair("976", "MN"));
        countries.push_back(std::make_pair("692", "MH"));
        countries.push_back(std::make_pair("389", "MK"));
        countries.push_back(std::make_pair("230", "MU"));
        countries.push_back(std::make_pair("356", "MT"));
        countries.push_back(std::make_pair("265", "MW"));
        countries.push_back(std::make_pair("960", "MV"));
        countries.push_back(std::make_pair("596", "MQ"));
        countries.push_back(std::make_pair("1670", "MP"));
        countries.push_back(std::make_pair("1664", "MS"));
        countries.push_back(std::make_pair("222", "MR"));
        countries.push_back(std::make_pair("441624", "IM"));
        countries.push_back(std::make_pair("256", "UG"));
        countries.push_back(std::make_pair("255", "TZ"));
        countries.push_back(std::make_pair("60", "MY"));
        countries.push_back(std::make_pair("52", "MX"));
        countries.push_back(std::make_pair("972", "IL"));
        countries.push_back(std::make_pair("33", "FR"));
        countries.push_back(std::make_pair("246", "IO"));
        countries.push_back(std::make_pair("290", "SH"));
        countries.push_back(std::make_pair("358", "FI"));
        countries.push_back(std::make_pair("679", "FJ"));
        countries.push_back(std::make_pair("500", "FK"));
        countries.push_back(std::make_pair("691", "FM"));
        countries.push_back(std::make_pair("298", "FO"));
        countries.push_back(std::make_pair("505", "NI"));
        countries.push_back(std::make_pair("31", "NL"));
        countries.push_back(std::make_pair("47", "NO"));
        countries.push_back(std::make_pair("264", "NA"));
        countries.push_back(std::make_pair("678", "VU"));
        countries.push_back(std::make_pair("687", "NC"));
        countries.push_back(std::make_pair("227", "NE"));
        countries.push_back(std::make_pair("672", "NF"));
        countries.push_back(std::make_pair("234", "NG"));
        countries.push_back(std::make_pair("64", "NZ"));
        countries.push_back(std::make_pair("977", "NP"));
        countries.push_back(std::make_pair("674", "NR"));
        countries.push_back(std::make_pair("683", "NU"));
        countries.push_back(std::make_pair("682", "CK"));
        countries.push_back(std::make_pair("225", "CI"));
        countries.push_back(std::make_pair("41", "CH"));
        countries.push_back(std::make_pair("57", "CO"));
        countries.push_back(std::make_pair("86", "CN"));
        countries.push_back(std::make_pair("237", "CM"));
        countries.push_back(std::make_pair("56", "CL"));
        countries.push_back(std::make_pair("61", "CC"));
        countries.push_back(std::make_pair("1", "CA"));
        countries.push_back(std::make_pair("242", "CG"));
        countries.push_back(std::make_pair("236", "CF"));
        countries.push_back(std::make_pair("243", "CD"));
        countries.push_back(std::make_pair("420", "CZ"));
        countries.push_back(std::make_pair("357", "CY"));
        countries.push_back(std::make_pair("61", "CX"));
        countries.push_back(std::make_pair("506", "CR"));
        countries.push_back(std::make_pair("599", "CW"));
        countries.push_back(std::make_pair("238", "CV"));
        countries.push_back(std::make_pair("53", "CU"));
        countries.push_back(std::make_pair("268", "SZ"));
        countries.push_back(std::make_pair("963", "SY"));
        countries.push_back(std::make_pair("599", "SX"));
        countries.push_back(std::make_pair("996", "KG"));
        countries.push_back(std::make_pair("254", "KE"));
        countries.push_back(std::make_pair("211", "SS"));
        countries.push_back(std::make_pair("597", "SR"));
        countries.push_back(std::make_pair("686", "KI"));
        countries.push_back(std::make_pair("855", "KH"));
        countries.push_back(std::make_pair("1869", "KN"));
        countries.push_back(std::make_pair("269", "KM"));
        countries.push_back(std::make_pair("239", "ST"));
        countries.push_back(std::make_pair("421", "SK"));
        countries.push_back(std::make_pair("82", "KR"));
        countries.push_back(std::make_pair("386", "SI"));
        countries.push_back(std::make_pair("850", "KP"));
        countries.push_back(std::make_pair("965", "KW"));
        countries.push_back(std::make_pair("221", "SN"));
        countries.push_back(std::make_pair("378", "SM"));
        countries.push_back(std::make_pair("232", "SL"));
        countries.push_back(std::make_pair("248", "SC"));
        countries.push_back(std::make_pair("7", "KZ"));
        countries.push_back(std::make_pair("1345", "KY"));
        countries.push_back(std::make_pair("65", "SG"));
        countries.push_back(std::make_pair("46", "SE"));
        countries.push_back(std::make_pair("249", "SD"));
        countries.push_back(std::make_pair("1809", "DO"));
        countries.push_back(std::make_pair("1829", "DO"));
        countries.push_back(std::make_pair("1767", "DM"));
        countries.push_back(std::make_pair("253", "DJ"));
        countries.push_back(std::make_pair("45", "DK"));
        countries.push_back(std::make_pair("1284", "VG"));
        countries.push_back(std::make_pair("49", "DE"));
        countries.push_back(std::make_pair("967", "YE"));
        countries.push_back(std::make_pair("213", "DZ"));
        countries.push_back(std::make_pair("1", "US"));
        countries.push_back(std::make_pair("598", "UY"));
        countries.push_back(std::make_pair("262", "YT"));
        countries.push_back(std::make_pair("1", "UM"));
        countries.push_back(std::make_pair("961", "LB"));
        countries.push_back(std::make_pair("1758", "LC"));
        countries.push_back(std::make_pair("856", "LA"));
        countries.push_back(std::make_pair("688", "TV"));
        countries.push_back(std::make_pair("886", "TW"));
        countries.push_back(std::make_pair("1868", "TT"));
        countries.push_back(std::make_pair("90", "TR"));
        countries.push_back(std::make_pair("94", "LK"));
        countries.push_back(std::make_pair("423", "LI"));
        countries.push_back(std::make_pair("371", "LV"));
        countries.push_back(std::make_pair("676", "TO"));
        countries.push_back(std::make_pair("370", "LT"));
        countries.push_back(std::make_pair("352", "LU"));
        countries.push_back(std::make_pair("231", "LR"));
        countries.push_back(std::make_pair("266", "LS"));
        countries.push_back(std::make_pair("66", "TH"));
        countries.push_back(std::make_pair("228", "TG"));
        countries.push_back(std::make_pair("235", "TD"));
        countries.push_back(std::make_pair("1649", "TC"));
        countries.push_back(std::make_pair("218", "LY"));
        countries.push_back(std::make_pair("379", "VA"));
        countries.push_back(std::make_pair("1784", "VC"));
        countries.push_back(std::make_pair("971", "AE"));
        countries.push_back(std::make_pair("376", "AD"));
        countries.push_back(std::make_pair("1268", "AG"));
        countries.push_back(std::make_pair("93", "AF"));
        countries.push_back(std::make_pair("1264", "AI"));
        countries.push_back(std::make_pair("1340", "VI"));
        countries.push_back(std::make_pair("354", "IS"));
        countries.push_back(std::make_pair("98", "IR"));
        countries.push_back(std::make_pair("374", "AM"));
        countries.push_back(std::make_pair("355", "AL"));
        countries.push_back(std::make_pair("244", "AO"));
        countries.push_back(std::make_pair("1684", "AS"));
        countries.push_back(std::make_pair("54", "AR"));
        countries.push_back(std::make_pair("61", "AU"));
        countries.push_back(std::make_pair("43", "AT"));
        countries.push_back(std::make_pair("297", "AW"));
        countries.push_back(std::make_pair("91", "IN"));
        countries.push_back(std::make_pair("35818", "AX"));
        countries.push_back(std::make_pair("994", "AZ"));
        countries.push_back(std::make_pair("353", "IE"));
        countries.push_back(std::make_pair("62", "ID"));
        countries.push_back(std::make_pair("380", "UA"));
        countries.push_back(std::make_pair("974", "QA"));
        countries.push_back(std::make_pair("258", "MZ"));

        std::sort(countries.begin(),
                  countries.end(),
                  [](Country const & lhs, Country const & rhs) {
                    return lhs.first < rhs.first;
                  }
        );

        uint32_t codeOffset = 0;
        for (Country const & country : countries)
        {
            m_codeOffsets.push_back(codeOffset);

            for (char c : country.first)
            {
                m_codes.push_back(c);
            }
            m_codes.push_back('\0');

            codeOffset = m_codes.size();

            m_countries.push_back({country.second[0], country.second[1]});
        }

        std::cout << "i  start   number   country\n";
        for (uint32_t i = 0; i < m_codeOffsets.size(); ++i)
        {
            uint32_t index = m_codeOffsets[i];
            std::cout << i << " " << index << "  " << (char*)(&m_codes[index]) << "  " << m_countries[i].id[0] << m_countries[i].id[1] << "\n";
        }
    }



    int compare(char const * number, char const * code)
    {
        while (*number != '\0' && *code != '\0')
        {
            if (*number != *code)
            {
                return *number - *code;
            }

            ++number;
            ++code;
        }

        return 0;
    }



    CountryId getCountry(char const * number)
    {
        size_t low = 0;
        size_t high = m_codeOffsets.size();
        while (low != high)
        {
            size_t const middle = low + (high-low) / 2;
            uint32_t const codeOffset = m_codeOffsets[middle];
            char const * const code = &m_codes[codeOffset];
            int direction = compare(number, code);
            if (direction == 0)
            {
                return m_countries[middle];
            }
            else if (direction < 0)
            {
                high = middle;
            }
            else
            {
                low = middle + 1;
            }
        }

        return CountryId{'\0', '\0'};
    }


private:
    std::vector<CountryId> m_countries;
    std::vector<uint32_t> m_codeOffsets;
    std::vector<char> m_codes;
};


int main()
{
    PhoneBook phoneBook;

    std::array<char[9], 1000> numbers;
    common::Random random;

    for (int i = 0; i < 1; ++i)
    {
        common::genrateNumbers(numbers, random);
        for (auto & number : numbers)
        {
            CountryId country = phoneBook.getCountry(number);
            if (country.id[0] != 0)
            {
                std::cout << "Number '" << number << "' has country "
                          << country.id[0] << country.id[1] << "\n";
            }
            else
            {
                std::cout << "No match for number '" << number << "'\n";
            }
        }
    }
}
