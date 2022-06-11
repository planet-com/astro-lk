#ifndef __CUST_USB_H__
#define __CUST_USB_H__

#define CONFIG_USBD_LANG	"0409"

#define USB_VENDORID		(0x0E8D)
#define USB_PRODUCTID		(0x201C)
#define USB_VERSIONID		(0x0100)
#define USB_MANUFACTURER	"MediaTek"
#define USB_PRODUCT_NAME	"Android"
#define FASTBOOT_DEVNAME	"mt6752_device"
#define SN_BUF_LEN		19

#if defined(SUPPORT_U3) && defined(HAS_REDRIVER)
#define REDRIVER_C1             GPIO41
#define REDRIVER_C2             GPIO40
#define U3_SW_SEL               GPIO11
#endif

#endif /* __CUST_USB_H__ */
