let render (user:Data.user) => {
  open Components;
  fullScreen [
    row center::true middle::true fullHeight::true [
      padding [
        card [
          card_block [
            card_title "User",
            text user.email
          ]
        ]
      ]
    ]
  ]
};
