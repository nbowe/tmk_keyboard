# -*- mode: ruby -*-
# vi: set ft=ruby :

class String
  def unindent 
    gsub(/^#{scan(/^\s*/).min_by{|l|l.length}}/, "")
  end
end

# All Vagrant configuration is done below. The "2" in Vagrant.configure
# configures the configuration version (we support older styles for
# backwards compatibility). Please don't change it unless you know what
# you're doing.
Vagrant.configure(2) do |config|
  # For a complete reference, please see the online documentation at
  # https://docs.vagrantup.com.
  config.vm.box = "ubuntu/trusty64"

  config.vm.provider "virtualbox" do |vb|
    vb.memory = 2048
    vb.cpus = 2

    # Enable USB. Requires extension pack to be installed on host.
    vb.customize ["modifyvm", :id, "--usb", "on"]
    vb.customize ["modifyvm", :id, "--usbehci", "on"]
    # vb.customize ["modifyvm", :id, "--ioapic", "on"]

    # Add a USB filter so that Teensy HalfKay bootloader attaches.
    # TODO(nbowe): work out why this doesn't attach to guest and fix. vbox compat issue?
    #vb.customize ["usbfilter", "add", "0", 
    #  "--target", :id, 
    #  "--name", "HalfKay bootloader", 
    #  "--vendorid", "0x16C0"]

    # Add a USB filter so that Infinity Keyboard bootloader auto attaches.
    vb.customize ["usbfilter", "add", "0", 
      "--target", :id, 
      "--name", "Kiibohd DFU Bootloader", 
      "--vendorid", "0x1c11", "--productid", "0xb007"]
  end
  
  # vagrant plugin install vagrant-cachier
  if Vagrant.has_plugin?("vagrant-cachier")
    config.cache.scope = :machine
  end

  config.vm.provision "shell", inline: <<-SHELL.unindent
    sudo apt-get update
    # Sync time with host, to avoid 'Clock skew detected' when building.
    /usr/sbin/VBoxService --timesync-set-start --timesync-set-on-restore 1 --timesync-set-threshold 500

    sudo apt-get -y install build-essential
    sudo apt-get -y install git cmake ctags libusb-1.0-0-dev libusb-dev
    # For Teensy 1, Teensy 2, or other AVR based chip
    sudo apt-get -y install binutils-avr gcc-avr avr-libc gdb-avr avrdude
    # For Teensy 3, Infinity Keyboard, or another ARM based chip
    sudo apt-get -y install binutils-arm-none-eabi gcc-arm-none-eabi
    sudo apt-get -y install dfu-util dfu-programmer
    # For building bootloader
    #sudo apt-get -y install ruby ruby-dev
    #sudo gem install serialport
    sudo apt-get -y install screen

    # udev teensy rules
    wget -O /etc/udev/rules.d/49-teensy.rules https://www.pjrc.com/teensy/49-teensy.rules 2>/dev/null

    sudo -u vagrant git clone https://github.com/PaulStoffregen/teensy_loader_cli.git
    pushd teensy_loader_cli
    sudo -Hn -u vagrant make
    cp teensy_loader_cli /usr/bin
    popd

    # Modify motd.
    cat >/etc/motd <<MOTD
     WIP
     TMK firmware files are in /vagrant
     Example building default gh60 firmware:
       cd /vagrant/keyboard/gh60
       make clean && make all
     Example flashing:
       [push flash button on teensy]
       make dfu
    MOTD
  SHELL

  # vagrant plugin install vagrant-triggers
  if Vagrant.has_plugin?("vagrant-triggers")
    config.trigger.before :destroy do
      # info "Cleaning build artifacts from layouts."
      # run_remote  "cd /home/vagrant/layouts && git clean -fXd"
    end
  end
end
