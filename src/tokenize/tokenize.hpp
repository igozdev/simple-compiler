// Copyright (c) 2024 igozdev 
// See end of file for full copyright information
#pragma once
#include <vector>
#include "token.hpp"
#include <string_view>
#include <cctype>
#include <string>
#include <deque>
#include <cassert>

[[nodiscard]] inline auto tokenize(std::string_view src) noexcept -> std::vector<token> {
    static std::deque<std::string> strings;
    std::vector<token> result;
    for (auto i = 0zu; i < src.length();) {
        if      (std::isalpha(src[i]) || src[i] == '_') {
            std::size_t const end = src.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789", i);
            std::string_view const word = src.substr(i, end - i);
            if (auto const sym = [src, i, word]() noexcept {
                    for (auto const [str, sym] : symbols) {
                        if (word == str) {
                            return sym;
                        }
                    }
                    return symbol::none;
                    }()
                    ; sym != symbol::none) {
                result.push_back(token{ .type = token::symbol, .symbol_ = sym });
            }
            else {
                result.push_back(token{ .type = token::identifier, .string_ = word });
            }
            i += word.length();
        }
        else if (std::isdigit(src[i])) {
            std::size_t const end = src.find_first_not_of("0123456789", i);
            result.push_back(token{ .type = token::integer, .integer_ = std::stoull(std::string(src.substr(i, end - i))) });
            i = end;
        }
        else if (std::isspace(src[i])) {
            i++;
        }
        else if (src[i] == '\'') {
            if (src[i + 1] == '\\' && src[i + 3] == '\'') { // 0['] 1[\] 2[escape] 3[']
                                                            // TODO: bounds checking
                switch (src[i + 2]) {
                case '0':
                    result.push_back(token{ .type = token::character, .character_ = '\0' });
                    break;
                case 't':
                    result.push_back(token{ .type = token::character, .character_ = '\t' });
                    break;
                case 'n':
                    result.push_back(token{ .type = token::character, .character_ = '\n' });
                    break;
                }
                i += 4;
            }
            else if (src[i + 2] == '\'') {   // 0['] 1[char] 2[']
                result.push_back(token{ .type = token::character, .character_ = src[i + 1] });
                i += 3;
            }
            else {
                assert(false); // TODO
            }
        }
        else if (src[i] == '"') {
            std::string str;
            i++;
            for (; i < src.length() && !(src[i] == '"' && src[i - 1] != '\\'); i++) {
                if (src[i - 1] == '\\') {
                    switch (src[i]) {
                    case '0':
                        str.push_back('\0');
                        break;
                    case 't':
                        str.push_back('\t');
                        break;
                    case 'n':
                        str.push_back('\n');
                        break;
                    case '"':
                        str.push_back('"');
                        break;
                    }
                }
                else if (src[i] == '\\');
                else {
                    str.push_back(src[i]);
                }
            }
            i++;
            strings.push_back(str);
            result.push_back(token{ .type = token::string, .string_ = std::string_view(strings.back()) });
        }
        else {
            auto const [sym, len] = [src, i]() noexcept {
                struct result_type { symbol _0; std::size_t _1; };
                constexpr std::size_t op_lengths[] = { 3, 2, 1 }; // reversed order so that longer operators are not split
                for (auto const length : op_lengths) {
                    for (auto const [str, sym] : symbols) {
                        if (src.substr(i, length) == str) {
                            return result_type{ sym, length };
                        }
                    }
                }
                return result_type{ symbol::none, 0 };
                }();
            assert(sym != symbol::none); // TODO
            result.push_back({ .type = token::symbol, .symbol_ = sym });
            i += len;
        }
    }
    return result;
}

// MIT License
// 
// Copyright (c) 2024 igozdev
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
