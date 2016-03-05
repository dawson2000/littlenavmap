/*****************************************************************************
* Copyright 2015-2016 Alexander Barthel albar965@mailbox.org
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
*****************************************************************************/

#include "maplayer.h"

MapLayer::MapLayer(int minimumRange, int maximumRange)
{
  minRange = minimumRange;
  maxRange = maximumRange;
}

MapLayer MapLayer::clone(int minimumRange, int maximumRange) const
{
  MapLayer retval = *this;
  retval.minRange = minimumRange;
  retval.maxRange = maximumRange;
  return retval;
}

MapLayer& MapLayer::airports(bool value)
{
  layerAirport = value;
  return *this;
}

MapLayer& MapLayer::airportDetail(bool value)
{
  layerAirportDetail = value;
  return *this;
}

MapLayer& MapLayer::airportSource(layer::AirportSource source)
{
  src = source;
  return *this;
}

MapLayer& MapLayer::airportOverviewRunway(bool value)
{
  layerAirportOverviewRunway = value;
  return *this;
}

MapLayer& MapLayer::airportDiagram(bool value)
{
  layerAirportDiagram = value;
  return *this;
}

MapLayer& MapLayer::airportSoft(bool value)
{
  layerAirportSoft = value;
  return *this;
}

MapLayer& MapLayer::airportNoRating(bool value)
{
  layerAirportNoRating = value;
  return *this;
}

MapLayer& MapLayer::airportSymbolSize(int size)
{
  layerAirportSymbolSize = size;
  return *this;
}

MapLayer& MapLayer::airportIdent(bool value)
{
  layerAirportIdent = value;
  return *this;
}

MapLayer& MapLayer::airportName(bool value)
{
  layerAirportName = value;
  return *this;
}

MapLayer& MapLayer::airportInfo(bool value)
{
  layerAirportInfo = value;
  return *this;
}

bool MapLayer::operator<(const MapLayer& other) const
{
  return minRange < other.minRange;
}

QDebug operator<<(QDebug out, const MapLayer& record)
{
  QDebugStateSaver saver(out);

  out.nospace().noquote() << "MapLayer["
  << record.minRange << "-" << record.maxRange << "]";

  return out;
}