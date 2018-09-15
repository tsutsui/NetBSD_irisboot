/*
 * Copyright (c) 2018 Naruaki Etomi
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Silicon Graphics "IRIS" series MIPS processors machine bootloader.
 */

struct consdev {
	char	*cn_name;	/* console device name */
	int	address;	/* address */
	int	speed;		/* speed(serial only) */
	void	(*cn_probe)	/* probe hardware and fill in consdev info */
		    (struct consdev *);
	void	(*cn_init)	/* turn on as console */
		    (struct consdev *);
	int	(*cn_getc)	/* getchar interface */
		    (void *);
	void	(*cn_putc)	/* putchar interface */
		    (void *, int);
	int	(*cn_scan)	/* scan interface */
		    (void *);
	int	cn_pri;		/* pecking order; the higher the better */
	void	*cn_dev;	/* device data tag */
};

/* values for cn_pri - reflect our policy for console selection */
#define CN_DEAD		0	/* device doesn't exist */
#define CN_NORMAL	1	/* device exists but is nothing special */
#define CN_INTERNAL	2	/* "internal" bit-mapped display */
#define CN_REMOTE	3	/* serial interface with remote bit set */
