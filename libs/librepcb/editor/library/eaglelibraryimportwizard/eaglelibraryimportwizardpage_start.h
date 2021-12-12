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

#ifndef LIBREPCB_EDITOR_EAGLELIBRARYIMPORTWIZARDPAGE_START_H
#define LIBREPCB_EDITOR_EAGLELIBRARYIMPORTWIZARDPAGE_START_H

/*******************************************************************************
 *  Includes
 ******************************************************************************/
#include <QtCore>
#include <QtWidgets>

#include <memory>

/*******************************************************************************
 *  Namespace / Forward Declarations
 ******************************************************************************/
namespace librepcb {
namespace editor {

class EagleLibraryImportWizardContext;

namespace Ui {
class EagleLibraryImportWizardPage_Start;
}

/*******************************************************************************
 *  Class EagleLibraryImportWizardPage_Start
 ******************************************************************************/

/**
 * @brief The EagleLibraryImportWizardPage_Start class
 */
class EagleLibraryImportWizardPage_Start final : public QWizardPage {
  Q_OBJECT

public:
  // Constructors / Destructor
  EagleLibraryImportWizardPage_Start() = delete;
  EagleLibraryImportWizardPage_Start(
      const EagleLibraryImportWizardPage_Start& other) = delete;
  EagleLibraryImportWizardPage_Start(
      std::shared_ptr<EagleLibraryImportWizardContext> context,
      QWidget* parent = nullptr) noexcept;
  ~EagleLibraryImportWizardPage_Start() noexcept;

  // Operator Overloadings
  EagleLibraryImportWizardPage_Start& operator=(
      const EagleLibraryImportWizardPage_Start& rhs) = delete;

private:  // Data
  QScopedPointer<Ui::EagleLibraryImportWizardPage_Start> mUi;
  std::shared_ptr<EagleLibraryImportWizardContext> mContext;
};

/*******************************************************************************
 *  End of File
 ******************************************************************************/

}  // namespace editor
}  // namespace librepcb

#endif
