// Copyright 2018 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#ifndef DEIIO_BASE_UTCTIME_H_
#define DEIIO_BASE_UTCTIME_H_

#include <deiio/base/Types.h>

namespace deiio {

/**
 * Time stamp in UTC, in microseconds resolution.
 *
 * This class is immutable.
 * It's recommended to pass it by value, since it's passed in register
 * on x86_64.
 */
class UtcTime {
 public:
  // Constructs an invalid UtcTime.
  UtcTime();

  /**
   * Constructs a UtcTime at specific time.
   *
   * @param microSecondsSinceEpoch
   */
  explicit UtcTime(int64_t microSecondsSinceEpoch);

  // default copy/assignment are Okay

  string toString() const;

  bool valid() const { return microSecondsSinceEpoch_ > 0; }

  bool before(UtcTime rhs) const {
    return microSecondsSinceEpoch_ < rhs.microSecondsSinceEpoch_;
  }

  bool after(UtcTime rhs) const {
    return microSecondsSinceEpoch_ > rhs.microSecondsSinceEpoch_;
  }

  bool equals(UtcTime rhs) const {
    return microSecondsSinceEpoch_ == rhs.microSecondsSinceEpoch_;
  }

  // for internal usage.
  int64_t microSecondsSinceEpoch() const {
    return microSecondsSinceEpoch_;
  }

  // Get time of now
  static UtcTime now();
  static UtcTime invalid();

  static const int kMicroSecondsPerSecond = 1000 * 1000;

 private:
  int64_t microSecondsSinceEpoch_;
};

inline bool operator<(UtcTime lhs, UtcTime rhs) {
  return lhs.before(rhs);
}

inline bool operator==(UtcTime lhs, UtcTime rhs) {
  return lhs.equals(rhs);
}

/**
 * Gets time difference of two timestamps, result in seconds.
 *
 * @param high, low
 * @return  (high-low) in seconds
 */
inline double timeDifference(UtcTime high, UtcTime low) {
  int64_t diff = high.microSecondsSinceEpoch() - low.microSecondsSinceEpoch();
  return static_cast<double>(diff) / UtcTime::kMicroSecondsPerSecond;
}

/**
 * Add @c seconds to given timestamp.
 *
 * @param timestamp, seconds
 * @return UtcTime
 */
inline UtcTime addTime(UtcTime timestamp, double seconds) {
  int64_t delta =
    static_cast<int64_t>(seconds * UtcTime::kMicroSecondsPerSecond);
  return UtcTime(timestamp.microSecondsSinceEpoch() + delta);
}

}  // namespace deiio

#endif  // DEIIO_BASE_UTCTIME_H_

