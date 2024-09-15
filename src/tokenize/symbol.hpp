// Copyright (c) 2024 igozdev 
// See end of file for full copyright information
#pragma once
#include <string_view>

enum class symbol {
    none,
    
    kw_as,
    kw_break,
    kw_const,
    kw_else,
    kw_enum,
    kw_false,
    kw_fn,
    kw_for,
    kw_if,
    kw_let,
    kw_match,
    kw_return,
    kw_static,
    kw_struct,
    kw_true,
    kw_using,
    kw_while,
    kw_null,
    kw_import,
    kw_bool,
    kw_char,
    kw_i8,
    kw_i16,
    kw_i32,
    kw_i64,
    kw_u8,
    kw_u16,
    kw_u32,
    kw_u64,

    op_lbrace,          // {
    op_rbrace,          // }
    op_lparen,          // (
    op_rparen,          // )
    op_comma,           // ,
    op_semicolon,       // ;
    op_colon,           // :
    op_colon_colon,     // ::
    op_dot,             // .
    op_minus_great,     // ->
    op_plus,            // +
    op_minus,           // -
    op_star,            // *
    op_slash,           // /
    op_per,             // %
    op_and,             // &
    op_caret,           // ^
    op_bar,             // |
    op_bang,            // !
    op_compl,           // ~
    op_lbracket,        // [
    op_rbracket,        // ]
    op_plus_plus,       // ++
    op_minus_minus,     // --
    op_less,            // <
    op_less_equal,      // <=
    op_great,           // >
    op_great_equal,     // >=
    op_equal_equal,     // ==
    op_bang_equal,      // !=
    op_less_less,       // <<
    op_great_great,     // >>
    op_and_and,         // &&
    op_bar_bar,         // ||
    op_equal,           // =
    op_plus_equal,      // +=
    op_minus_equal,     // -=
    op_star_equal,      // *=
    op_slash_equal,     // /=
    op_per_equal,       // %=
    op_and_equal,       // &=
    op_caret_equal,     // ^=
    op_bar_equal,       // |=
    op_less_less_equal, // <<=
    op_great_great_equal,   // >>=
};

struct { std::string_view _0; symbol _1; } constexpr symbols[] = {
    { "@", symbol::none },

    { "as",     symbol::kw_as },
    { "break",  symbol::kw_break },
    { "const",  symbol::kw_const },
    { "else",   symbol::kw_else },
    { "enum",   symbol::kw_enum },
    { "false",  symbol::kw_false },
    { "fn",     symbol::kw_fn },
    { "for",    symbol::kw_for },
    { "if",     symbol::kw_if },
    { "let",    symbol::kw_let },
    { "match",  symbol::kw_match },
    { "return", symbol::kw_return },
    { "static", symbol::kw_static },
    { "struct", symbol::kw_struct },
    { "true",   symbol::kw_true },
    { "using",  symbol::kw_using },
    { "while",  symbol::kw_while },
    { "import", symbol::kw_import },
    { "null",   symbol::kw_null },
    { "bool",   symbol::kw_bool },
    { "char",   symbol::kw_char },
    { "i8",     symbol::kw_i8 },
    { "i16",    symbol::kw_i16 },
    { "i32",    symbol::kw_i32 },
    { "i64",    symbol::kw_i64 },
    { "u8",     symbol::kw_u8 },
    { "u16",    symbol::kw_u16 },
    { "u32",    symbol::kw_u32 },
    { "u64",    symbol::kw_u64 },
    
    { "{",      symbol::op_lbrace },
    { "}",      symbol::op_rbrace },
    { "(",      symbol::op_lparen },
    { ")",      symbol::op_rparen },
    { ",",      symbol::op_comma },
    { ";",      symbol::op_semicolon },
    { ":",      symbol::op_colon },
    { "::",     symbol::op_colon_colon },
    { ".",      symbol::op_dot },
    { "->",     symbol::op_minus_great },
    { "+",      symbol::op_plus },
    { "-",      symbol::op_minus },
    { "*",      symbol::op_star },
    { "/",      symbol::op_slash },
    { "%",      symbol::op_per },
    { "&",      symbol::op_and },
    { "^",      symbol::op_caret },
    { "|",      symbol::op_bar },
    { "!",      symbol::op_bang },
    { "~",      symbol::op_compl },
    { "[",      symbol::op_lbracket },
    { "]",      symbol::op_rbracket },
    { "++",     symbol::op_plus_plus },
    { "--",     symbol::op_minus_minus },
    { "<",      symbol::op_less },
    { "<=",     symbol::op_less_equal },
    { ">",      symbol::op_great },
    { ">=",     symbol::op_great_equal },
    { "==",     symbol::op_equal_equal },
    { "!=",     symbol::op_bang_equal },
    { "<<",     symbol::op_less_less },
    { ">>",     symbol::op_great_great },
    { "&&",     symbol::op_and_and },
    { "||",     symbol::op_bar_bar },
    { "=",      symbol::op_equal },
    { "+=",     symbol::op_plus_equal },
    { "-=",     symbol::op_minus_equal },
    { "*=",     symbol::op_star_equal },
    { "/=",     symbol::op_slash_equal },
    { "%=",     symbol::op_per_equal },
    { "&=",     symbol::op_and_equal },
    { "^=",     symbol::op_caret_equal },
    { "|=",     symbol::op_bar_equal },
    { "<<=",    symbol::op_less_less_equal },
    { ">>=",    symbol::op_great_great_equal },
};

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
