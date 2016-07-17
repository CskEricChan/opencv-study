srcs := $(shell find . -name "*.cpp")
objs := $(srcs:.cpp=.o)
deps := $(srcs:.cpp=.d)

target := $(shell pwd)
target := $(notdir $(target))
target := $(target).bin

LIBS += -lopencv_calib3d \
    -lopencv_core \
    -lopencv_features2d \
    -lopencv_flann \
    -lopencv_highgui \
    -lopencv_imgcodecs \
    -lopencv_imgproc \
    -lopencv_ml \
    -lopencv_objdetect \
    -lopencv_photo \
    -lopencv_shape \
    -lopencv_stitching \
    -lopencv_superres \
    -lopencv_ts \
    -lopencv_video \
    -lopencv_videoio \
    -lopencv_videostab

CC = g++

all: $(target)

$(target): $(objs)
	$(CC) -o $@ $^ $(LIBS)

%.d: %.cpp
	$(CC) -MM $< > $@

-include $(deps)

clean:
	rm -rf *.o *.d *.bin
