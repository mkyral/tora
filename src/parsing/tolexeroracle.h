/* BEGIN_COMMON_COPYRIGHT_HEADER
 *
 * TOra - An Oracle Toolkit for DBA's and developers
 *
 * Shared/mixed copyright is held throughout files in this product
 *
 * Portions Copyright (C) 2000-2001 Underscore AB
 * Portions Copyright (C) 2003-2005 Quest Software, Inc.
 * Portions Copyright (C) 2004-2009 Numerous Other Contributors
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation;  only version 2 of
 * the License is valid for this program.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 *      As a special exception, you have permission to link this program
 *      with the Oracle Client libraries and distribute executables, as long
 *      as you follow the requirements of the GNU GPL in regard to all of the
 *      software in the executable aside from Oracle client libraries.
 *
 *      Specifically you are not permitted to link this program with the
 *      Qt/UNIX, Qt/Windows or Qt Non Commercial products of TrollTech.
 *      And you are not permitted to distribute binaries compiled against
 *      these libraries.
 *
 *      You may link this product with any GPL'd Qt library.
 *
 * All trademarks belong to their respective owners.
 *
 * END_COMMON_COPYRIGHT_HEADER */

#ifndef TOLEXERORACLE_H_
#define TOLEXERORACLE_H_

#include "parsing/tsqllexer.h"

#include <QtCore/QObject>
#include <Qsci/qscilexercustom.h>
#include <Qsci/qscilexersql.h>

class QsciStyle;

class toLexerOracle : public QsciLexerCustom {
        Q_OBJECT;
public:
        enum Style {
                Default    = QsciLexerSQL::Default,     // white spaces only
                Comment    = QsciLexerSQL::Comment,
                Reserved   = QsciLexerSQL::Keyword,
                Builtin    = QsciLexerSQL::KeywordSet5,
                Identifier = QsciLexerSQL::Identifier,
                OneLine    = QsciLexerSQL::PlusPrompt,
                CommentMultiline,
                Failure,
                MaxStyle
        };

        toLexerOracle(QObject *parent = 0);
        virtual ~toLexerOracle();

        /* override - reimplemented from QsciLexerCustom */
        virtual const char *language() const;
        virtual QString description(int) const;
        virtual void styleText(int start, int end);

protected:
        char *lineText, *bufferText;
        unsigned lineLength, bufferLength;

        QMap<int,QString> styleNames;
    	QList<int> styleStack;
    	std::auto_ptr <SQLLexer::Lexer> lexer;
};

#endif /* TOLEXERORACLE_H_ */