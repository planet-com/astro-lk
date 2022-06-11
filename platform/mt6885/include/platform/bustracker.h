#ifndef __BUSTRACKER_H__

#define INFRA_TRACKER_BASE	0x10208000
#define INFRA_ENTRY_NUM		32

#define PERI_TRACKER_BASE	0x11279000
#define	PERI_ENTRY_NUM		16

#define BUSTRACKER_TIMEOUT	0x300

#define AR_TRACK_L(__base, __n)		(__base + 0x100 + 8 * (__n))
#define AR_TRACK_H(__base, __n)		(__base + 0x104 + 8 * (__n))
#define AW_TRACK_L(__base, __n)		(__base + 0x300 + 8 * (__n))
#define AW_TRACK_H(__base, __n)		(__base + 0x304 + 8 * (__n))

#endif /* end of __BUSTRACKER_H__ */
