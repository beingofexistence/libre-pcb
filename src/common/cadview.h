/*
 * EDA4U - Professional EDA for everyone!
 * Copyright (C) 2013 Urban Bruhin
 * http://eda4u.ubruhin.ch/
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

#ifndef CADVIEW_H
#define CADVIEW_H

/*****************************************************************************************
 *  Includes
 ****************************************************************************************/

#include <QtCore>
#include <QtWidgets>
#include "units.h"

/*****************************************************************************************
 *  Forward Declarations
 ****************************************************************************************/

class CADScene;

/*****************************************************************************************
 *  Class CADView
 ****************************************************************************************/

/**
 * @brief The CADView class
 *
 * @author ubruhin
 *
 * @date 2014-06-22
 */
class CADView : public QGraphicsView
{
        Q_OBJECT

    public:

        // Enums
        enum GridType {noGrid, gridLines, gridDots};

        // Constructors / Destructor
        explicit CADView(QWidget* parent = 0);
        virtual ~CADView();

        // Getters
        CADScene*       getCadScene()   const;
        GridType        getGridType()   const {return mGridType;}
        const QColor&   getGridColor()  const {return mGridColor;}

        // Setters
        void setGridType(GridType type);
        void setGridColor(const QColor& color);

        // Zoom Functions
        void zoomIn();
        void zoomOut();
        void zoomAll();

        // Static Functions
        static qreal getZoomFactor() {return sZoomFactor;}
        static void setZoomFactor(qreal factor) {sZoomFactor = factor;}

    protected:

        // Inherited Methods
        virtual void drawBackground(QPainter* painter, const QRectF& rect);
        virtual void wheelEvent(QWheelEvent* event);
        virtual void mouseMoveEvent(QMouseEvent* event);

    signals:

        void mousePosChanged(const Point& newPos);

    private:

        // make some methods inaccessible...
        CADView();
        CADView(const CADView& other);
        CADView& operator=(const CADView& rhs);

        GridType mGridType;
        QColor mGridColor;

        // Static Variables
        static qreal sZoomFactor;

};

#endif // CADVIEW_H
