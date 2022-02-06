all:
clean:
	-rm tmp/*.png tmp/*.jpg tmp/*.jpeg

tmp/%.png: tmp/%.jpg
	convert $< $@
tmp/%.png: tmp/%.jpeg
	convert $< $@
define eval_downscale
tmp/%.$(1).png: tmp/%.png
	convert $$< -depth 16 -gamma 0.454545 -filter lanczos -resize $(1) -gamma 2.2 -depth 8 $$@
endef
downscale = $(eval $(call eval_downscale,$(1)))
$(call downscale,512)
$(call downscale,1024)
define eval_download
tmp/$(notdir $(1)):
	curl $(1) -o $$@ -s
endef
download = $(eval $(call eval_download,$(1)))
define eval_lossless
$(1).webp: tmp/$(2).png
	cwebp $$< -o $$@ -lossless -m 6 -q 100
all: $(1).webp
endef
lossless = $(eval $(call eval_lossless,$(1),$(2)))

$(call download,https://web.archive.org/web/20190909072451if_/http://www.public-domain-photos.com/free-stock-photos-4/flowers/yellow-rose-3.jpg)
$(call lossless,lossless/rose,yellow-rose-3.512)
$(call download,https://web.archive.org/web/20111213095701if_/http://www.minecraftwiki.net/images/8/85/Fizyplankton.png)
$(call lossless,lossless/tux,Fizyplankton)
$(call download,https://upload.wikimedia.org/wikipedia/commons/4/47/PNG_transparency_demonstration_1.png)
$(call lossless,lossless/dice,PNG_transparency_demonstration_1)
$(call download,https://upload.wikimedia.org/wikipedia/commons/d/d3/Compass_Card_transparent.png)
$(call lossless,lossless/compass,Compass_Card_transparent)
