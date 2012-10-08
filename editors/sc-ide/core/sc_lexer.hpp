/*
    SuperCollider Qt IDE
    Copyright (c) 2012 Jakob Leben & Tim Blechmann
    http://www.audiosynth.com

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
*/

#ifndef SCIDE_CORE_SC_LEXER_HPP_INCLUDED
#define SCIDE_CORE_SC_LEXER_HPP_INCLUDED

#include "../widgets/code_editor/tokens.hpp"

#include <QVector>
#include <QRegExp>
#include <QString>

namespace ScIDE {

class ScLexer
{
public:

    Token::Type nextToken ( QString const & text, int offset, int & lengthOfMatch );

    static void initLexicalRules();

private:
    struct LexicalRule
    {
        LexicalRule(): type(Token::Unknown) {}
        LexicalRule( Token::Type t, const QString &s ): type(t), expr(s) {}

        Token::Type type;
        QRegExp expr;
    };

    static void initKeywordsRules();
    static void initBuiltinsRules();

    static QVector<LexicalRule> mLexicalRules;
};

}

#endif // SCIDE_CORE_SC_LEXER_HPP_INCLUDED