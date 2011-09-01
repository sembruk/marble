//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2010,2011 Bernhard Beschow <bbeschow@cs.tu-berlin.de>
//

#ifndef MARBLE_TILESCALINGTEXTUREMAPPER_H
#define MARBLE_TILESCALINGTEXTUREMAPPER_H


#include "TextureMapperInterface.h"
#include "TileId.h"

#include <QtCore/QCache>
#include <QtGui/QImage>

class QPainter;
class QPixmap;

namespace Marble
{

class TileScalingTextureMapper : public TextureMapperInterface
{
    Q_OBJECT

 public:
    TileScalingTextureMapper( StackedTileLoader *tileLoader,
                              QCache<TileId, QPixmap> *cache,
                              QObject *parent = 0 );

    virtual void mapTexture( GeoPainter *painter,
                             const ViewportParams *viewport,
                             const QRect &dirtyRect,
                             TextureColorizer *texColorizer );

    virtual void setRepaintNeeded();

 private Q_SLOTS:
    void updateTile( const TileId &id );
    void updateTiles();

 private:
    void mapTexture( GeoPainter *painter,
                     const ViewportParams *viewport,
                     TextureColorizer *texColorizer );

 private:
    StackedTileLoader *const m_tileLoader;
    QCache<TileId, QPixmap> *const m_cache;
    bool   m_repaintNeeded;
    QImage m_canvasImage;
    int    m_radius;
};

}

#endif
