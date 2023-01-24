/*
 * LibrePCB - Professional EDA for everyone!
 * Copyright (C) 2013 LibrePCB Developers, see AUTHORS.md for contributors.
 * https://librepcb.org/
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*******************************************************************************
 *  Includes
 ******************************************************************************/
#include "cmdsymbolinstancetextsreset.h"

#include "cmdsymbolinstancetextadd.h"
#include "cmdsymbolinstancetextremove.h"

#include <librepcb/core/project/schematic/items/si_symbol.h>

#include <QtCore>

/*******************************************************************************
 *  Namespace
 ******************************************************************************/
namespace librepcb {
namespace editor {

/*******************************************************************************
 *  Constructors / Destructor
 ******************************************************************************/

CmdSymbolInstanceTextsReset::CmdSymbolInstanceTextsReset(
    SI_Symbol& symbol) noexcept
  : UndoCommandGroup(tr("Reset symbol texts")), mSymbol(symbol) {
}

CmdSymbolInstanceTextsReset::~CmdSymbolInstanceTextsReset() noexcept {
}

/*******************************************************************************
 *  Inherited from UndoCommand
 ******************************************************************************/

bool CmdSymbolInstanceTextsReset::performExecute() {
  // Remove all texts
  foreach (SI_Text* text, mSymbol.getTexts()) {
    appendChild(new CmdSymbolInstanceTextRemove(mSymbol, *text));
  }

  // Create new texts
  for (const Text& text : mSymbol.getDefaultTexts()) {
    appendChild(new CmdSymbolInstanceTextAdd(
        mSymbol, *new SI_Text(mSymbol.getSchematic(), text)));
  }

  // execute all child commands
  return UndoCommandGroup::performExecute();  // can throw
}

/*******************************************************************************
 *  End of File
 ******************************************************************************/

}  // namespace editor
}  // namespace librepcb
