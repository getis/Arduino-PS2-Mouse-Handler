#ifndef PS2MouseHandler_h

#define PS2MouseHandler_h
#define PS2_MOUSE_REMOTE 1
#define PS2_MOUSE_STREAM 2

class PS2MouseHandler
{
  private:
    int _clock_pin;
    int _data_pin;
    int _mode;
    int _initialized;
    int _enabled;
    int _disabled;
    bool _no_mouse;

    uint8_t _last_status;
    uint8_t _status;
    int16_t _x_movement;
    int16_t _y_movement;
    int8_t _z_movement;

    uint8_t _device_id;
    int get_device_id();
    uint8_t read_byte();
    int read_bit();
    int16_t read_movement_x(int);
    int16_t read_movement_y(int);
    int16_t read_movement_z(int);
    uint8_t get_button_mask(int);
    void pull_high(int);
    void pull_low(int);
    void set_mode(int);
    void write(int);
    int read();

  public:
    PS2MouseHandler(int, int, int mode = PS2_MOUSE_REMOTE);
    int initialize();
    int clock_pin();
    int data_pin();
    int device_id();
    int status();
    int x_movement();
    int y_movement();
    int z_movement();
    bool button(int);
    bool clicked(int);
    void get_data();
    void enable_data_reporting();
    void disable_data_reporting();
    void set_remote_mode();
    void set_stream_mode();
    void set_resolution(int);
    void set_scaling_2_1();
    void set_scaling_1_1();
    void set_sample_rate(int, bool);
};

#endif
