#include <linux/joystick.h>

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>

int main(int argc, char** argv) {
  int fd = open("/dev/input/js0", O_RDWR);
  if (fd < 0) {
    perror("Could not open joystick device");
    return 1;
  }
  __u8 num_axes;
  int ret = ioctl(fd, JSIOCGAXES, &num_axes);
  if (ret < 0) {
    perror("Failed to get number of axes");
    return 1;
  }
  printf("Number of axes: %d\n", num_axes);
  return 0;
}
