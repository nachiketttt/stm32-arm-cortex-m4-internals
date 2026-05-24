# 004_BitBanding

Modifying the 7th bit of the byte at SRAM address 0x20000200 using bit banding and without bit banding
- Without bit banding the whole byte is read and then modified 
- With bit banding the process is much simpler and consumes less instructions as the 7th bit present at address 0x20000200 is given a separate specific address **alias_base +( 32 * (bit_band_memory_addr - bit_band_base ) ) + bit * 4** 
- The value present at bit alias address is then modified this is an atomic operation and is also interrupt safe 
