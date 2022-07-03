class Product < ApplicationRecord
  has_one_attached :image
  validates :name, presence: true, length: { minimum: 5 }
  validates :description, presence: true
  validates :price, presence: true
  belongs_to :user
  after_commit :add_default_image, on: [:create, :update]

  def add_default_image
    unless image.attached?
      pics = %w[hendrix.jpg johnny_cash.jpg madonna.jpg pink_floyd.jpg]
      self.image.attach(io: File.open(Rails.root.join("app", "assets", "images", pics.sample)), filename: pics.sample, content_type: "image/jpg")
    end
  end

end
