/*
 * (C) Copyright 2017-2018 UCAR
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 */

#ifndef UFO_GNSSRO_QC_ROOBSERROR_H_
#define UFO_GNSSRO_QC_ROOBSERROR_H_

#include <ostream>
#include <string>
#include <vector>

#include "boost/shared_ptr.hpp"

#include "ioda/ObsDataVector.h"
#include "oops/util/ObjectCounter.h"
#include "ufo/filters/FilterBase.h"
#include "ROobserror.interface.h"

namespace eckit {
  class Configuration;
}

namespace ioda {
  template <typename DATATYPE> class ObsDataVector;
  class ObsSpace;
}

namespace ufo {

/// ROobserror: calculate observational errors

class ROobserror : public FilterBase,
                   private util::ObjectCounter<ROobserror> {
 public:
  static const std::string classname() {return "ufo::ROobserror";}

  ROobserror(ioda::ObsSpace &, const eckit::Configuration &,
             boost::shared_ptr<ioda::ObsDataVector<int> >,
             boost::shared_ptr<ioda::ObsDataVector<float> >);
  ~ROobserror();

 private:
  void print(std::ostream &) const override;
  void applyFilter(const std::vector<bool> &, std::vector<std::vector<bool>> &) const override;

  F90roerr key_;
};

}  // namespace ufo

#endif  // UFO_GNSSRO_QC_ROOBSERROR_H_
